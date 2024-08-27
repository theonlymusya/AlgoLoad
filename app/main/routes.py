# -*- coding: utf-8 -*-
import os
from datetime import datetime
from os import path

from flask import (
    current_app,
    flash,
    make_response,
    redirect,
    render_template,
    request,
    send_from_directory,
    url_for,
)
from flask_login import current_user, login_required

from app import dataBase
from app.main import bluePrint
from app.main.forms import (
    EditProfileForm,
    ReportSubmitForm,
    TaskReceiveForm,
    TaskSubmitForm,
)
from app.models import Report, User


@bluePrint.route("/")
@bluePrint.route("/index")
def index():
    # Приветствие и инструкция
    return render_template("index.html", title="Главная страница")


@bluePrint.route("/favicon.ico")
def favicon():
    cur_abs_path = os.path.abspath(os.path.curdir)

    return send_from_directory(
        directory=cur_abs_path + "/app/static",
        filename="favicon.ico",
        mimetype="image/vnd.microsoft.icon",
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


# Пути к ресурсным файлам юзверя
@bluePrint.route("/user/<username>/<path:path>", methods=["GET"])
def send_textures(username, path):
    # print(f">>> [GET] path = {path}")

    # Определяем, в какой папке лежат данные для нашего пользователя
    cur_user = User.query.filter_by(username=username).first_or_404()
    cur_folder = (
        os.path.abspath(os.path.curdir)
        + "/volume/userdata/"
        + cur_user.local_folder
        + "/page"
    )

    # print(f"cur_folder = {cur_folder}")

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
    # print("=======> ", cur_folder + "/page.html")
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
    return send_from_directory(
        directory="/home/flask_skipod/volume/vars",
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
            print("Could not write to file")
            return make_response(
                ("Not sure why," " but we couldn't write the file to server", 500)
            )

        total_chunks = int(request.form["dztotalchunkcount"])

        if current_chunk + 1 == total_chunks:
            # This was the last chunk, the file should be complete and the size we expect
            if os.path.getsize(save_path) != int(request.form["dztotalfilesize"]):
                print(
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
                print(f"File {file.filename} has been uploaded successfully")
                file_is_uploaded = True
        else:
            print(
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


# @bluePrint.route('/admin', methods=['GET', 'POST'])
# @login_required
# def admin():
#     return render_template('admin.html', title='Администрирование')


@bluePrint.route("/upload_task", methods=["GET", "POST"])
@login_required
def upload_task():
    form = TaskSubmitForm()
    # Сохраняем изменения на странице
    if form.validate_on_submit():
        # Определим вспомогательные переменные
        cur_abs_path = os.path.abspath(os.path.curdir)
        usr_tsk_path = "/volume/userdata/" + current_user.local_folder + "/task"
        usr_pge_path = "/volume/userdata/" + current_user.local_folder + "/page"

        # Нужно создать ещё и локальную директорию для отображения результатов
        if not os.path.exists(cur_abs_path + usr_pge_path):
            os.makedirs(
                cur_abs_path + usr_pge_path + "/Json_models", mode=0x777, exist_ok=True
            )

        # Нужно записать в эту директорию загнанные данные и запустить архитектора.
        if os.path.exists(cur_abs_path + usr_tsk_path):
            # Запись комментария юзверя
            fd = os.open(
                cur_abs_path + usr_tsk_path + "/Task_code.txt", os.O_RDWR | os.O_CREAT
            )
            os.write(fd, bytes(form.task_code.data, "utf-8"))
            os.close(fd)

            # Запись разметки, загруженной юзверем
            # В сети предлагают чекать имя файла через werkzeug, чего я сделать не могу из-за отсутствия в werkzeug этой функции
            graph_name = form.file_data.data.filename
            form.file_data.data.save(cur_abs_path + usr_tsk_path + "/" + graph_name)

            # Найдём xml конфиг соответствующего юзера и его папку для JSON-моделей
            graph_config_file = cur_abs_path + usr_tsk_path + "/" + graph_name
            graph_output_dirs = cur_abs_path + usr_pge_path + "/Json_models"
            cpp_output_file_path = graph_output_dirs + "/graphData.json"

            # Нужно снести все старые данные графа
            try:
                os.remove(os.path.join(graph_output_dirs, "graphData.json"))
            except OSError:
                pass

            if graph_config_file.endswith(".json"):
                print(f"*\n*\n*\n>>>>>>> Загрузили .json\n*")
                os.replace(graph_config_file, cpp_output_file_path)
            else:  # новый архитектор
                # graph_appgen_path_new_cpp = cur_abs_path + "/scripts/main"
                graph_appgen_path_new_cpp = cur_abs_path + "/architect/main"
                os_command_new_cpp = f"{graph_appgen_path_new_cpp} {graph_config_file} {cpp_output_file_path}"

                print(f"*\n*\n*\n>>>>>>> OS run {os_command_new_cpp}\n*")
                os.system(os_command_new_cpp)

            # сохранение таска в бд
            current_user.task_file = form.file_data.data.filename
            dataBase.session.commit()

        # Всё необходимое создано, возвращаемся на страницу пользователя
        user = User.query.filter_by(username=current_user.username).first_or_404()

        return render_template(
            "user.html", title="Моя страница", user=user, graph_name=graph_name
        )

    return render_template("upload_task.html", title="Загрузка задания", form=form)


@bluePrint.route("/receive_task", methods=["GET"])
@login_required
def receive_task():
    # print(">>> in /receive_task")

    # Просмотр результирующей картинки.
    cur_abs_path = os.path.abspath(os.path.curdir)
    user_task_path = f"{cur_abs_path}/volume/userdata/{current_user.local_folder}/task"

    # Настройка формы
    form = TaskReceiveForm()
    if os.path.exists(user_task_path):
        # Закинем комментарии юзера в его же форму
        try:
            fd = os.open(user_task_path + "/Task_code.txt", os.O_RDONLY)
            bytes_data = os.read(fd, 16384)
            form.task_code.data = bytes_data.decode("utf-8")
            # <-- тут вылетает ошибка при декодировании (редко)
            # UnicodeDecodeError: 'utf-8' codec can't decode byte 0xb5 in position 83: invalid start byte

            # with open(user_task_path + "/Task_code.txt", "rb") as f:
            #     form.task_code.data = f.read()
        except:
            form.task_code.data = "Ошибка получения описания задачи."

        # Получаем xml-код пользователя (или оставляем пустым если был загружен .json)
        try:
            fd = os.open(user_task_path + "/" + current_user.task_file, os.O_RDONLY)
            bytes_data = os.read(fd, 16384)
            xml_code = bytes_data.decode("utf-8")
        except:
            xml_code = "Ошибка получения XML кода задачи."

    # Настройка пути к визуализационной странице и рендер всего ресурса
    # algoview_source = "/user/" + current_user.username + "/get_data" # больше не работает

    # old: http://localhost:3001/user/q000/AlgoViewPage.html
    # algoview_source = "/user/" + current_user.username + "/AlgoViewPage.html"

    # static: http://localhost:3001/static/AlgoViewPage.html
    algoview_source = "/static/AlgoViewPage.html"

    json_data_source = "/user/" + current_user.username + "/Json_models/graphData.json"

    return render_template(
        "result_task.html",
        title="Результат",
        form=form,
        algoview_source=algoview_source,
        json_data_source=json_data_source,
        xml_code=xml_code,
    )
