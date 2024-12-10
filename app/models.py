from datetime import datetime

from flask_login import UserMixin
from werkzeug.security import check_password_hash, generate_password_hash

from app import dataBase, login


class Report(UserMixin, dataBase.Model):
    id = dataBase.Column(dataBase.Integer, primary_key=True)
    user_id = dataBase.Column(dataBase.Integer, dataBase.ForeignKey("user.id"))
    report_name = dataBase.Column(dataBase.String(100))
    mark = dataBase.Column(dataBase.Integer)
    date_creation = dataBase.Column(dataBase.DateTime, default=datetime.utcnow())
    comment = dataBase.Column(dataBase.String(1000))
    teacher_name = dataBase.Column(dataBase.String(64), default="")

    var_num = dataBase.Column(dataBase.Integer)
    var_file = dataBase.Column(dataBase.String(128))


class Group(UserMixin, dataBase.Model):
    id = dataBase.Column(dataBase.Integer, primary_key=True)
    groupname = dataBase.Column(dataBase.String(64), index=True, unique=True)

    def __repr__(self):
        return "<Group {}>".format(self.groupname)


class Group_user(UserMixin, dataBase.Model):
    id = dataBase.Column(dataBase.Integer, primary_key=True)
    groupid = dataBase.Column(dataBase.Integer, dataBase.ForeignKey("group.id"))
    userid = dataBase.Column(dataBase.Integer, dataBase.ForeignKey("user.id"))

    def __repr__(self):
        return "<Group_user {}>".format(self.groupid)


class User(UserMixin, dataBase.Model):
    id = dataBase.Column(dataBase.Integer, primary_key=True)
    username = dataBase.Column(dataBase.String(64), index=True, unique=True)
    password_hash = dataBase.Column(dataBase.String(128))
    local_folder = dataBase.Column(dataBase.String(128))

    about_me = dataBase.Column(dataBase.String(140))
    last_seen = dataBase.Column(dataBase.DateTime, default=datetime.utcnow())

    var_num = dataBase.Column(dataBase.Integer)
    var_file = dataBase.Column(dataBase.String(128))
    var_name = dataBase.Column(dataBase.String(128))
    task_file = dataBase.Column(dataBase.String(128))

    def set_password(self, password):
        self.password_hash = generate_password_hash(password)

    def check_password(self, password):
        return check_password_hash(self.password_hash, password)

    def __repr__(self):
        return "<User {}>".format(self.username)


@login.user_loader
def load_user(user_id):
    return User.query.get(int(user_id))


def debug_print(*values: object):
    # flask_app.logger.info("...")

    try:
        print("\nPYTHON DEBUG MESSAGE: ")

        for value in values:
            print(value, end=" ")

        print(f"\n{'=' * 50}\n")

    except:
        pass


# убрали докер, путь поменялся.
# надо обновлять для каждого сервера пока не заведем конфиг
abs_volume_path = "/home/algoload/www/AlgoLoadProject/volume/"
