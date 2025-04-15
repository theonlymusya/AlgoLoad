# !/bin/bash

. .venv/bin/activate

flask db migrate

readonly LOG_FOLDER="logs"
readonly LOG_FILE="$LOG_FOLDER/microbial.log"

mkdir -p $LOG_FOLDER
touch $LOG_FILE

# launch web server with config file
exec gunicorn --config gunicorn_config.py flask_skipod:appFlask
