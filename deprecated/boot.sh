#!/bin/bash
# this script is used to boot a Docker container
source .venv/bin/activate

# old: source /home/new_user/Desktop/Flask_ss/.venv/bin/activate
# flask db migrate

while true; do
    flask db upgrade
    if [[ "$?" == "0" ]]; then
        break
    fi
    echo Upgrade command failed, retrying in 5 secs...
    sleep 5
done

# create user folders
# python Folders_create.py

readonly LOG_FOLDER="logs"
readonly LOG_FILE="$LOG_FOLDER/microbial.log"

mkdir -p $LOG_FOLDER
touch $LOG_FILE

# launch web server
exec gunicorn -b 0.0.0.0:3001 --timeout 300 --access-logfile $LOG_FILE --error-logfile $LOG_FILE flask_skipod:appFlask
