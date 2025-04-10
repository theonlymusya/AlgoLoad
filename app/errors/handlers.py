from flask import render_template

from app import dataBase
from app.errors import bluePrint
from app.models import debug_print


@bluePrint.app_errorhandler(404)
def not_found_error(error):
    debug_print(f">>> error 404: {error}")
    return render_template("errors/404.html"), 404


@bluePrint.app_errorhandler(500)
def internal_error(error):
    debug_print(f">>> error 500: {error}")
    dataBase.session.rollback()
    return render_template("errors/500.html"), 500
