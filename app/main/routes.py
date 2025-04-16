# -*- coding: utf-8 -*-
import os
from datetime import datetime
from flask import current_app
from flask_login import current_user, login_required
from app.main.architect_job import ArchitectJob
from app.main.receive_task_responce import ReceiveTaskResponce
from app.models import Report, User, abs_volume_path, debug_print
from app import dataBase
from app.main import bluePrint
from flask.json import jsonify
import shutil


from flask import (
    flash,
    make_response,
    redirect,
    render_template,
    request,
    send_from_directory,
    url_for,
)

from app.main.forms import (
    EditProfileForm,
    TaskReceiveForm,
    TaskSubmitForm,
)


@bluePrint.route("/")
@bluePrint.route("/index")
def index():
    # Приветствие и инструкция
    return render_template("index.html", title="Главная страница")


@bluePrint.route("/app/", defaults={"path": ""})
@bluePrint.route("/app/<path:path>")
def frontend_handler(path):
    flutter_app_folder = current_app.config.get("FLUTTER_WEB_APP_FOLDER")

    # Полный путь до запрашиваемого файла
    full_path = os.path.join(flutter_app_folder, path)

    # Если файл существует (например, стили, скрипты), отдаём его
    if path != "" and os.path.exists(full_path):
        return send_from_directory(flutter_app_folder, path)

    # Если файла нет – всегда отдаём index.html, чтобы клиентская маршрутизация Flutter взяла управление
    index_path = os.path.join(flutter_app_folder, "index.html")
    if os.path.exists(index_path):
        return send_from_directory(flutter_app_folder, "index.html")

    return jsonify({"result": "invalid index path"}), 400


@bluePrint.route("/favicon.ico")
def favicon():
    cur_abs_path = os.path.abspath(os.path.curdir)

    return send_from_directory(
        directory=cur_abs_path + "/app/static",
        filename="favicon.ico",
        mimetype="image/vnd.microsoft.icon",
    )


@bluePrint.route("/.well-known/assetlinks.json")
def assetlinks():
    cur_abs_path = os.path.abspath(os.path.curdir)

    return send_from_directory(
        directory=cur_abs_path + "/app/static/.well-known",
        filename="assetlinks.json",
        mimetype="application/json",
    )


@bluePrint.route("/logs", methods=["GET"])
def getAllLogs():
    cur_abs_path = os.path.abspath(os.path.curdir)

    return send_from_directory(
        directory=cur_abs_path + "/logs", filename="microbial.log"
    )


@bluePrint.before_request
def before_request():
    if current_user.is_authenticated:
        current_user.last_seen = datetime.utcnow()
        # Flask-login уже добавил пользователя при обращении к current_user
        dataBase.session.add(current_user)
        # поэтому эта строка необязательна
        dataBase.session.commit()


# Пути к ресурсным файлам юзера
@bluePrint.route("/user/<username>/<path:path>", methods=["GET"])
def send_textures(username, path):
    # debug_print(f">>> [GET] path = {path}")

    # Определяем, в какой папке лежат данные для нашего пользователя
    cur_user = User.query.filter_by(username=username).first_or_404()
    cur_folder = (
        os.path.abspath(os.path.curdir)
        + "/volume/userdata/"
        + cur_user.local_folder
        + "/page"
    )

    # debug_print(f"cur_folder = {cur_folder}")

    # return send_from_directory(
    #     directory="/home/flask_skipod/volume/vars",
    #     filename=user.var_file,
    #     as_attachment=True,
    # )

    return send_from_directory(cur_folder, path)


@bluePrint.route("/user/<username>/get_data", methods=["GET"])
def render_static(username):
    # Определяем, в какой папке лежат данные для нашего пользователя
    cur_user = User.query.filter_by(username=username).first_or_404()
    cur_dir = os.path.curdir
    cur_dir = os.path.abspath(cur_dir)
    cur_dir = os.path.realpath(cur_dir)
    cur_folder = cur_dir + "/volume/userdata/" + cur_user.local_folder + "/page"
    # debug_print("=======> ", cur_folder + "/page.html")
    return send_from_directory(cur_folder, "/page.html")


@bluePrint.route("/user/<username>/home_page")
@login_required
def user_page(username):
    graph_name = request.args.get("graph_name")
    user = User.query.filter_by(username=username).first_or_404()
    return render_template(
        "user.html", title="Моя страница", user=user, graph_name=graph_name
    )


@bluePrint.route("/user/<username>/task")
@login_required
def download_var(username):
    user = User.query.filter_by(username=username).first_or_404()
    vars_path = abs_volume_path + "vars"

    return send_from_directory(
        # directory="/home/flask_skipod/volume/vars", # для докера
        directory=vars_path,  # без докера
        filename=user.var_file,
        as_attachment=True,
    )
    # return render_template('user.html', title='Моя страница', user=user, graph_name=graph_name)


@bluePrint.route("/upload_report/<path:filename>", methods=["GET", "POST"])
def download(filename):
    cur_abs_path = os.path.abspath(os.path.curdir)
    usr_report_path = "/volume/userdata/" + current_user.local_folder + "/reports"
    return send_from_directory(
        directory=cur_abs_path + usr_report_path, filename=filename
    )


@bluePrint.route("/upload_report", methods=["GET", "POST"])
@login_required
def upload_report():
    if request.method == "POST":
        # Отчёт уже был проверен
        if (
            Report.query.filter_by(user_id=current_user.id).count() != 0
            and Report.query.filter_by(user_id=current_user.id).first().mark != None
        ):
            return make_response("Отчёт уже проверен, загрузка нового невозможна.", 500)

        file_is_uploaded = False
        file = request.files["file"]

        save_path = (
            "volume/userdata/" + current_user.local_folder + "/reports/" + file.filename
        )
        current_chunk = int(request.form["dzchunkindex"])

        # If the file already exists it's ok if we are appending to it,
        # but not if it's new file that would overwrite the existing one
        if os.path.exists(save_path) and current_chunk == 0:
            # 400 and 500s will tell dropzone that an error occurred and show an error
            os.remove(save_path)

        try:
            with open(save_path, "ab") as f:
                f.seek(int(request.form["dzchunkbyteoffset"]))
                f.write(file.stream.read())
        except OSError:
            # log.exception will include the traceback so we can see what's wrong
            debug_print("Could not write to file")
            return make_response(
                ("Not sure why," " but we couldn't write the file to server", 500)
            )

        total_chunks = int(request.form["dztotalchunkcount"])

        if current_chunk + 1 == total_chunks:
            # This was the last chunk, the file should be complete and the size we expect
            if os.path.getsize(save_path) != int(request.form["dztotalfilesize"]):
                debug_print(
                    f"File {file.filename} was completed, "
                    f"but has a size mismatch."
                    f"Was {os.path.getsize(save_path)} but we"
                    f" expected {request.form['dztotalfilesize']} "
                )
                return make_response(
                    (
                        "При отправке произошла ошибка, попробуте отправить повторно.",
                        500,
                    )
                )
            else:
                debug_print(f"File {file.filename} has been uploaded successfully")
                file_is_uploaded = True
        else:
            debug_print(
                f"Chunk {current_chunk + 1} of {total_chunks} "
                f"for file {file.filename} complete"
            )

        if file_is_uploaded:
            upload_file = request.files["file"]
            # Определим вспомогательные переменные
            cur_abs_path = os.path.abspath(os.path.curdir)
            usr_report_path = (
                "/volume/userdata/" + current_user.local_folder + "/reports"
            )
            # Нужно записать в директорию /reports загнанные данные.
            report_name = upload_file.filename
            # Отчёты ранее не загружались
            if Report.query.filter_by(user_id=current_user.id).count() == 0:
                new_report = Report(
                    report_name=report_name,
                    user_id=current_user.id,
                    date_creation=datetime.utcnow(),
                    var_num=current_user.var_num,
                    var_file=current_user.var_file,
                )
                # upload_file.save(cur_abs_path + usr_report_path + "/" + report_name)
                dataBase.session.add(new_report)
                dataBase.session.commit()
                return make_response(("Success", 200))

            # Отчёт уже был проверен
            # if Report.query.filter_by(user_id=current_user.id).first().mark != None:
            #     return render_template('report_checked.html', title='Мои отчеты')

            # Отчёт отправлен повторно
            report = Report.query.filter_by(user_id=current_user.id).first()
            report.report_name = report_name
            report.date_creation = datetime.utcnow()
            dataBase.session.commit()

            # Всё необходимое создано, возвращаемся на страницу пользователя
            return make_response(("Success", 200))
    reports_query = Report.query.filter_by(user_id=current_user.id)
    arReports = []
    for report in reports_query:
        arReports.append(
            {
                "report_name": report.report_name,
                "data_creation": str(report.date_creation).partition(".")[0],
                "mark": report.mark,
                "comment": report.comment,
                "teacher_name": report.teacher_name,
            }
        )
    return render_template("reports.html", title="Мои отчеты", reports=arReports)


@bluePrint.route("/edit_profile", methods=["GET", "POST"])
@login_required
def edit_profile():
    form = EditProfileForm(current_user.username)
    # Сохраняем изменения на странице
    if form.validate_on_submit():
        current_user.username = form.username.data
        current_user.about_me = form.about_me.data
        current_user.local_folder = form.local_folder.data
        dataBase.session.commit()
        flash("Your changes have been saved!")
        return redirect(url_for("main.edit_profile"))
    # Только зашли
    if request.method == "GET":
        form.username.data = current_user.username
        form.about_me.data = current_user.about_me
    return render_template("edit_profile.html", title="Изменить данные", form=form)


# todo: remove method
# @bluePrint.route('/admin', methods=['GET', 'POST'])
# @login_required
# def admin():
#     return render_template('admin.html', title='Администрирование')


@bluePrint.route("/upload_task", methods=["GET", "POST"])
@login_required
def upload_task():
    form = TaskSubmitForm()

    if form.validate_on_submit():
        ArchitectJob(form.task_code.data, form.file_data.data)

        # Возвращаемся на страницу пользователя
        user = User.query.filter_by(username=current_user.username).first_or_404()
        graph_name = form.file_data.data.filename

        return render_template(
            "user.html", title="Моя страница", user=user, graph_name=graph_name
        )

    return render_template("upload_task.html", title="Загрузка задания", form=form)


@bluePrint.route("/api/upload_task", methods=["GET", "POST"])
@login_required
def upload_task_app():
    form = TaskSubmitForm()

    if form.validate_on_submit():
        job = ArchitectJob(form.task_code.data, form.file_data.data)
        return job.to_responce()

    return (
        f"Invalid form: form.task_code = {form.task_code.data}, form.submit = {form.file_data.data}, form.submit = {form.submit.data}, ",
        400,
    )


# Просмотр результирующей картинки. для сайта
@bluePrint.route("/receive_task", methods=["GET"])
@login_required
def receive_task():
    responce = ReceiveTaskResponce()

    form = TaskReceiveForm()
    form.task_code.data = responce.user_comment

    return render_template(
        "result_task.html",
        title="Результат",
        form=form,
        algoview_source=responce.algoview_static_link,
        json_data_source=responce.json_graph_data_link,
        xml_code=responce.graph_source_config,
    )


# Просмотр результирующей картинки. для приложеня
@bluePrint.route("/api/receive_task", methods=["GET"])
@login_required
def receive_task_app():
    responce = ReceiveTaskResponce()
    return responce.to_json(), 200


@bluePrint.route("/api/username", methods=["GET"])
@login_required
def api_get_username():
    username = current_user.username
    return jsonify({"result": username}), 200
