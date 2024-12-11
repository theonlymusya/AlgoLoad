# -*- coding: utf-8 -*-
from flask import flash, redirect, render_template, request, url_for
from flask.json import jsonify
from flask_login import current_user, login_user, logout_user
from werkzeug.urls import url_parse

# import traceback

from app import dataBase
from app.auth import bluePrint
from app.auth.forms import LoginForm
from app.models import User, debug_print

# from app.auth.forms import RegisterForm


# @bluePrint.after_request
# def log_response_headers(response):
#     # # Здесь доступны заголовки для анализа или логирования
#     # print("Response Headers (after_request):", response.headers)
#     # return response


# По умолчанию функция просмотра принимает только запрос GET,
# это переопределяется в methods
@bluePrint.route("/login", methods=["GET", "POST"])
def login_usr():
    # Так медленнее, но лучше читаемость.
    form = LoginForm()

    # Уже залогинены
    if current_user.is_authenticated:
        return redirect(url_for("main.index"))

    # Отправили заполненную форму
    if form.validate_on_submit():
        user = User.query.filter_by(username=form.username.data).first()
        if user is None or not user.check_password(form.password.data):
            flash("Invalid username or password")
            return redirect(url_for("auth.login_usr"))
        login_user(user, remember=form.remember_me.data)
        next_page = request.args.get("next")
        if not next_page or url_parse(next_page).netloc != "":
            return redirect(url_for("main.index"))
        return redirect(next_page)

    # Пришли сюда в первый раз
    return render_template("auth/login.html", title="Вход в систему", form=form)


@bluePrint.route("/app/login", methods=["GET", "POST"])
def login_usr_app():
    form = LoginForm()

    # Уже залогинены
    if current_user.is_authenticated:
        return jsonify({"result": "Already authorized"}), 200

    # Отправили заполненную форму
    if form.validate_on_submit():
        user = User.query.filter_by(username=form.username.data).first()
        if user is None or not user.check_password(form.password.data):
            # используется для отправки временных сообщений пользователю.
            # flash("Invalid username or password")

            return jsonify({"result": "Invalid username or password"}), 400

        login_user(user, remember=form.remember_me.data)
        return jsonify({"result": "Authorized successfully"}), 200

    # Форма не заполнена
    return jsonify({"result": "Login form not filled"}), 400


@bluePrint.route("/logout")
def logout_usr():
    logout_user()
    return redirect(url_for("main.index"))


@bluePrint.route("/app/logout")
def logout_usr_app():
    logout_user()
    return jsonify({"result": "Logout successfully"})


# @bluePrint.route('/register', methods=['GET', 'POST'])
# def register_usr():
#     form = RegisterForm()
#     # Отправили заполненную форму
#     if form.validate_on_submit():
#         user = User.query.filter_by(username=form.username.data).first()
#         if user is None:
#             new_user = User(username=form.username.data, local_folder=form.username.data)
#             new_user.set_password(form.password.data)
#             dataBase.session.add(new_user)
#             next_page = request.args.get('next')
#             dataBase.session.commit()
#             new_usrs = User.query.all()
#             debug_print(new_usrs)
#             if not next_page or url_parse(next_page).netloc != '':
#                 return redirect(url_for('auth.login_usr'))
#             return redirect(next_page)
#         else:
#             flash('User login already exists')
#             return redirect(url_for('auth.register_usr'))
#     return render_template('auth/register.html', title='Регистрация', form=form)
