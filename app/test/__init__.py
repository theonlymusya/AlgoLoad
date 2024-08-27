from flask import Blueprint

bluePrint = Blueprint("test", __name__)

from app.test import routes
