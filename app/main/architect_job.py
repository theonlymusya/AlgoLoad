import os
import shutil
import subprocess
import traceback
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
                mode=0o777,  # Исправлено на восьмеричный формат
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

            # Обрабатываем входной файл конфигурации графа в зависимости от его типа

            if graph_input_config_file.endswith(".json"):
                debug_print(f">>>>>>> Загрузили .json")
                shutil.copy(graph_input_config_file, graph_output_config_file)

            else:
                architect_script_file = cur_abs_path + "/architect/main"
                command = [
                    architect_script_file,
                    graph_input_config_file,
                    graph_output_config_file,
                ]

                self._execute_architect(command)

            # сохранение таска в бд
            debug_print(f">>>>>>> Cохранение таска в бд {graph_name}")
            current_user.task_file = graph_name
            dataBase.session.commit()

        debug_print(f">>>>>>> upload_task finish")
        self.result = True

    def _execute_architect(self, command):
        """Выполнение скрипта архитектора с обработкой ошибок"""
        debug_print(f">>>>>>> Launching architect command: {command}")

        process = None
        try:
            debug_print(f">>>>>>> Starting architect process")
            process = subprocess.Popen(
                command,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
            )

            stdout, stderr = process.communicate(timeout=30)
            return_code = process.wait()

            debug_print(f">>>>>>> Architect exit code: {return_code}")
            debug_print(f">>>>>>> Architect stdout: {stdout}")
            debug_print(f">>>>>>> Architect stderr: {stderr}")

            if return_code != 0:
                raise subprocess.CalledProcessError(
                    return_code, command, output=stdout, stderr=stderr
                )

        except subprocess.CalledProcessError as e:
            debug_print(f">>>>>>> Process error [code {e.returncode}]: {e.stderr}")
            debug_print(f">>>>>>> Command output: {e.stdout}")
            if process and process.poll() is None:
                debug_print(f">>>>>>> Terminating hanging process")
                process.terminate()
                process.wait(timeout=5)
            self.result = False
            return
        except subprocess.TimeoutExpired as e:
            debug_print(f">>>>>>> Timeout error: {str(e)}")
            if process and process.poll() is None:
                debug_print(f">>>>>>> Killing timed out process")
                process.kill()
                process.wait()
            self.result = False
            return
        except Exception as e:
            debug_print(f">>>>>>> Critical error: {str(e)}")
            debug_print(f">>>>>>> Traceback: {traceback.format_exc()}")
            if process and process.poll() is None:
                process.kill()
            self.result = False
            return
        finally:
            if process:
                process.stdout.close()
                process.stderr.close()

    def to_json(self):
        return jsonify(
            {
                "result": "OK" if self.result else "Failure",
            }
        )

    def to_responce(self):
        return (
            self.to_json(),
            200 if self.result else 400,
        )
