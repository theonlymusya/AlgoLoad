import os
import shutil
from flask.json import jsonify
from flask_login import current_user
from app.models import debug_print
from app import dataBase


class ArchitectJob:
    def __init__(self, user_comment, uploaded_file):
        self.result = False

        # self.user_comment = user_comment
        # self.uploaded_file = uploaded_file

        # Определим вспомогательные переменные
        cur_abs_path = os.path.abspath(os.path.curdir)
        local_volume_user_dir = "/volume/userdata/" + current_user.local_folder
        volume_user_task_dir = cur_abs_path + local_volume_user_dir + "/task"
        volume_user_page_dir = cur_abs_path + local_volume_user_dir + "/page"
        volume_user_page_models_dir = volume_user_page_dir + "/Json_models"

        # Нужно создать ещё и локальную директорию для отображения результатов
        if not os.path.exists(volume_user_page_dir):
            os.makedirs(
                volume_user_page_models_dir,
                mode=0x777,
                exist_ok=True,
            )

        # Нужно записать в эту директорию загнанные данные и запустить архитектора.
        if os.path.exists(volume_user_task_dir):
            # Запись комментария юзера
            fd = os.open(
                volume_user_task_dir + "/Task_code.txt",
                os.O_RDWR | os.O_CREAT,
            )
            os.write(fd, bytes(user_comment, "utf-8"))
            os.close(fd)

            # (???) В сети предлагают чекать имя файла через werkzeug,
            # чего я сделать не могу из-за отсутствия в werkzeug этой функции
            # https://tedboy.github.io/flask/generated/generated/werkzeug.FileStorage.html
            graph_name = uploaded_file.filename

            # Найдём xml конфиг соответствующего юзера и его папку для JSON-моделей
            graph_input_config_file = volume_user_task_dir + "/" + graph_name
            graph_output_config_file = volume_user_page_models_dir + "/graphData.json"
            graph_input_config_last_file = volume_user_task_dir + "/last_input_config"

            # Запись разметки, загруженной юзером
            debug_print(f">>>>>>> uploaded_file = {uploaded_file}")
            debug_print(f">>>>>>> graph_config_file = {graph_input_config_file}")
            uploaded_file.save(graph_input_config_file)

            # для удобства дуюлируем файл
            shutil.copy(graph_input_config_file, graph_input_config_last_file)

            # Нужно снести все старые данные графа
            try:
                os.remove(os.path.join(volume_user_page_models_dir, "graphData.json"))
            except OSError:
                pass

            if graph_input_config_file.endswith(".json"):
                debug_print(f">>>>>>> Загрузили .json")
                shutil.copy(graph_input_config_file, graph_output_config_file)

            else:
                architect_script_file = cur_abs_path + "/architect/main"
                os_command_new_cpp = f"{architect_script_file} {graph_input_config_file} {graph_output_config_file}"

                debug_print(f">>>>>>> OS run {os_command_new_cpp}")

                try:
                    os.system(os_command_new_cpp)
                except:
                    debug_print(f">>>>>>> failed OS run")
                    pass

            # сохранение таска в бд
            debug_print(f">>>>>>> Cохранение таска в бд {graph_name}")
            current_user.task_file = graph_name
            dataBase.session.commit()

        debug_print(f">>>>>>> upload_task finish")
        self.result = True

    def to_json(self):
        return jsonify(
            {
                "result": "OK" if self.result else "Null",
            }
        )

    def to_responce(self):
        return (
            self.to_json(),
            200 if self.result else 400,
        )
