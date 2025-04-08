import logging
import os
from datetime import timedelta
from logging.handlers import RotatingFileHandler, SMTPHandler

from flask import Flask
from flask_bootstrap import Bootstrap
from flask_cors import CORS
from flask_login import LoginManager
from flask_migrate import Migrate
from flask_sqlalchemy import SQLAlchemy

from config import Config

# Объявление всего
dataBase = SQLAlchemy()
migrate = Migrate()
login = LoginManager()
login.login_view = "auth.login_usr"
login.login_message = "Sign in or register to access"
bootstrap = Bootstrap()


def _register_blueprint(app_flask):
    from app.errors import bluePrint as errors_BP

    app_flask.register_blueprint(errors_BP)

    from app.auth import bluePrint as auth_BP

    app_flask.register_blueprint(auth_BP)

    from app.main import bluePrint as main_BP

    app_flask.register_blueprint(main_BP)

    from app.admin import bluePrint as admin_BP

    app_flask.register_blueprint(admin_BP)

    from app.teacher import bluePrint as teacher_BP

    app_flask.register_blueprint(teacher_BP)

    from app.test import bluePrint as test_BP

    app_flask.register_blueprint(test_BP)


def create_app(config_class=Config()):
    # Само приложение
    app_flask = Flask(__name__)
    app_flask.config.from_object(config_class)

    # app_flask.debug = True

    # максимальный возраст кэшируемых файлов, находящихся в /static
    # https://stackoverflow.com/questions/41144565/flask-does-not-see-change-in-js-file
    # https://stackoverflow.com/questions/34066804/disabling-caching-in-flask/54422901#54422901

    # app_flask.config["SEND_FILE_MAX_AGE_DEFAULT"] = timedelta(seconds=1)
    app_flask.config["SEND_FILE_MAX_AGE_DEFAULT"] = 0
    app_flask.config["TEMPLATES_AUTO_RELOAD"] = True

    # enable CORS
    # https://stackoverflow.com/questions/65630743/how-to-solve-flutter-web-api-cors-error-only-with-dart-code/66879350#66879350
    # https://enable-cors.org/server_flask.html
    # cors = CORS(app_flask)

    # todo: replace
    # Укажите здесь конкретный домен, с которого будут приходить запросы
    allowed_origins = [
        config_class.FLUTTER_APP_BASE_URL_DEV,
        config_class.FLUTTER_APP_BASE_URL_STAGING,
        config_class.FLUTTER_APP_BASE_URL_PROD,
    ]

    # Настройка CORS
    CORS(
        app_flask,
        supports_credentials=True,
        resources={
            r"/*": {
                "origins": allowed_origins,
                "allow_headers": ["Content-Type", "Authorization"],
                "expose_headers": ["Access-Control-Allow-Credentials"],
            }
        },
    )

    dataBase.init_app(app_flask)
    migrate.init_app(app_flask, dataBase)
    login.init_app(app_flask)
    bootstrap.init_app(app_flask)

    _register_blueprint(app_flask)

    # Настройка регистратора электронной почты
    if not app_flask.debug:
        if app_flask.config["MAIL_SERVER"]:
            auth = None
            if app_flask.config["MAIL_USERNAME"] or app_flask.config["MAIL_PASSWORD"]:
                auth = (
                    app_flask.config["MAIL_USERNAME"],
                    app_flask.config["MAIL_PASSWORD"],
                )
            secure = None
            if app_flask.config["MAIL_USE_TLS"]:
                secure = ()
            mail_handler = SMTPHandler(
                mailhost=(
                    app_flask.config["MAIL_SERVER"],
                    app_flask.config["MAIL_PORT"],
                ),
                fromaddr="no-reply@" + app_flask.config["MAIL_SERVER"],
                toaddrs=app_flask.config["ADMINS"],
                subject="Microbial failure",
                credentials=auth,
                secure=secure,
            )
            mail_handler.setLevel(logging.ERROR)
            app_flask.logger.addHandler(mail_handler)

    # Настройка журналирования ошибок в файлы
    # if not app_flask.debug:

    if not os.path.exists("logs"):
        os.mkdir("logs")

    # Заводим новый лог-файл
    file_handler = RotatingFileHandler(
        "logs/microbial.log",
        maxBytes=500000,
        backupCount=20,
    )

    file_handler.setFormatter(
        logging.Formatter(
            "[%(asctime)s  ] [Flask] [%(levelname)s] "
            "%(message)s [int %(pathname)s:%(lineno)d]"
        )
    )

    file_handler.setLevel(logging.INFO)

    # Настраиваем приложение на его использование
    app_flask.logger.addHandler(file_handler)
    app_flask.logger.setLevel(logging.INFO)
    app_flask.logger.info("Microbial startup")

    return app_flask
