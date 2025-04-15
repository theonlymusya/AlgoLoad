# !/bin/bash

. .venv/bin/activate

flask db migrate

readonly LOG_FOLDER="logs"
readonly LOG_FILE="$LOG_FOLDER/microbial.log"

mkdir -p $LOG_FOLDER
touch $LOG_FILE

# launch web server
exec gunicorn -b 0.0.0.0:3001 --timeout 300 --access-logfile $LOG_FILE --error-logfile $LOG_FILE flask_skipod:appFlask

# launch web server without logs (tmp)
# exec gunicorn -b 0.0.0.0:3001 --timeout 300 flask_skipod:appFlask
