FROM python:3.6-alpine

# add GCC on alpine: https://stackoverflow.com/questions/50984864/installing-gcc-from-source-on-alpine

RUN apk add --no-cache bash make build-base; \
    apk add curl; \
    apk add --upgrade qt5-qtbase; \
    adduser -D flask_skipod

WORKDIR /home/flask_skipod

#WORKDIR /home/new_user/Desktop/Flask_ss/
#!requirements.txt
#WORKDIR /home/new_user/Desktop/Flask_ss/venv/bin
#!RUN pip install gunicorn

# SHELL [ "/bin/bash", "-l", "-c" ]

#!COPY requirements.txt requirements.txt
#COPY --chown=flask_skipod:flask_skipod requirements.txt requirements.txt\
#        app app \
# architect_old architect_old \
#     migrations migrations \
#     logs userdata \
#     app.db flask_skipod.py config.py Folders_create.py boot.sh ./


COPY --chown=flask_skipod:flask_skipod app app
COPY --chown=flask_skipod:flask_skipod scripts scripts
# COPY --chown=flask_skipod:flask_skipod architect_old architect_old
COPY --chown=flask_skipod:flask_skipod architect architect
COPY --chown=flask_skipod:flask_skipod migrations migrations
COPY --chown=flask_skipod:flask_skipod logs logs
COPY --chown=flask_skipod:flask_skipod new_user_folder new_user_folder
#COPY --chown=flask_skipod:flask_skipod volume/userdata userdata
COPY --chown=flask_skipod:flask_skipod requirements.txt flask_skipod.py config.py Folders_create.py boot.sh ./
#COPY --chown=flask_skipod:flask_skipod requirements.txt app.db flask_skipod.py config.py Folders_create.py boot.sh ./


RUN chmod -R 777 app scripts architect migrations logs new_user_folder\
    flask_skipod.py config.py Folders_create.py boot.sh
#!    app.db flask_skipod.py config.py Folders_create.py boot.sh

# компиляция ядра
# RUN (rm -rf scripts/main && cd ./architect && make && mv main ../scripts && cd ..)
RUN rm -rf scripts/main
RUN rm -rf scripts/*.o
RUN (cd ./architect && make)
RUN mv ./architect/main ./scripts

# установка нужных библиотек 
RUN python3 -m venv venv
RUN venv/bin/pip install --upgrade pip
RUN venv/bin/pip install -r requirements.txt
RUN venv/bin/pip install gunicorn

#!RUN venv/bin/pip install --upgrade pip
#!RUN venv/bin/pip install -r requirements.txt
#!RUN venv/bin/pip install gunicorn

#!COPY app app
#!COPY architect_old architect_old
#!COPY migrations migrations
#!COPY logs logs
#COPY userdata userdatall -r requirements.txt/
#!RUN venv/bin/pip install gunicorn

#!COPY app app
#!COPY architect_old architect_old
#!COPY migrations migrations
#!COPY logs logs
#!COPY userdata userdata
#!COPY app.db app.db
#!COPY flask_skipod.py c
#!COPY app.db app.db
#!COPY flask_skipod.py config.py Folders_create.py boot.sh ./

#!RUN chmod -R 777 app
#!RUN chmod -R 777 architect_old
#!RUN chmod -R 777 logs
#!RUN chmod -R 777 migrations
#!RUN chmod -R 777 userdata
#!RUN chmod -R 777 app.db
#!RUN chmod 777 flask_skipod.py
#!RUN chmod 777 Folders_create.py
#!RUN chmod 777 config.py
#!RUN chmod 777 boot.sh

# RUN (cd architect && make && mv main ../architect_old)

ENV FLASK_APP flask_skipod.py
ENV BIND 0.0.0.0:3001
ENV PORT 3001
#RUN #chown -R flask_skipod:flask_skipod ./
USER flask_skipod

EXPOSE 3001
CMD ["run", "--host", "0.0.0.0"]
ENTRYPOINT ["./boot.sh"]
