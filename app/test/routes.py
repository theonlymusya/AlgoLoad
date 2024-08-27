# -*- coding: utf-8 -*-
from app.test import bluePrint
from flask import jsonify, request, redirect, url_for


# # @bluePrint.route("/kkk/<data>")
# # @appFlask.route("/kkk/<data>", methods=["POST"])
# @bluePrint.route("/kkk/", methods=["GET", "POST"])


@bluePrint.route("/kkk/", methods=["GET", "POST"])
def jjjjjjjjj():

    if request.method == "POST":
        data = request.get_json()
        return jsonify({"status": "yes", "data": f"<{data}>"})
    else:
        return jsonify({"status": "fail", "data": "<empty>"})


# @bluePrint.route("/admin/reports/<path:filename>", methods=["GET", "POST"])
# def download(filename):
#     data = request.args.get("user")
#     cur_abs_path = os.path.abspath(os.path.curdir)
#     user_folder = User.query.filter_by(username=data).first().local_folder
#     usr_report_path = "/volume/userdata/" + user_folder + "/reports"
#     dir = cur_abs_path + usr_report_path
#     return send_from_directory(directory=dir, filename=filename, as_attachment=True)


# @bluePrint.route("/rrr")
# def logout_usr_13():
#     return redirect(url_for("main.index"))
