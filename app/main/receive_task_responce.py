import os
from flask.json import jsonify
from flask_login import current_user


class ReceiveTaskResponce:
    user_comment = ""
    graph_source_type = "xml"  # xml / json / cpp
    graph_source_config = ""
    algoview_static_link = ""
    json_graph_data_link = ""

    def __init__(self):
        cur_abs_path = os.path.abspath(os.path.curdir)
        user_task_dir = (
            f"{cur_abs_path}/volume/userdata/{current_user.local_folder}/task"
        )

        if os.path.exists(user_task_dir):
            try:
                fd = os.open(user_task_dir + "/Task_code.txt", os.O_RDONLY)
                bytes_data = os.read(fd, 16384)
                self.user_comment = bytes_data.decode("utf-8")
                # <-- тут вылетает ошибка при декодировании (редко)
                # UnicodeDecodeError: 'utf-8' codec can't decode byte 0xb5 in position 83: invalid start byte

                # with open(user_task_path + "/Task_code.txt", "rb") as f:
                #     self.user_comment = f.read()
            except:
                self.user_comment = "Ошибка получения описания задачи."

            # Получаем graph source config
            try:

                fd = os.open(user_task_dir + "/" + current_user.task_file, os.O_RDONLY)
                bytes_data = os.read(fd, 16384)
                self.graph_source_config = bytes_data.decode("utf-8")

            except:
                self.graph_source_config = "Ошибка получения XML кода задачи."

            try:
                self.graph_source_type = self.get_file_extension(current_user.task_file)
            except:
                self.graph_source_type = "null"

        # static: http://localhost:3001/static/AlgoViewPage.html
        self.algoview_static_link = "/static/AlgoViewPage.html"
        self.json_graph_data_link = (
            "/user/" + current_user.username + "/Json_models/graphData.json"
        )

    def get_file_extension(self, filename):
        # Разделяем строку по точке и возвращаем последний элемент
        return filename.split(".")[-1] if "." in filename else ""

    def to_json(self):
        return jsonify(
            {
                "user_comment": self.user_comment,
                "graph_source_type": self.graph_source_type,
                "graph_source_config": self.graph_source_config,
                "algoview_static_link": self.algoview_static_link,
                "json_graph_data_link": self.json_graph_data_link,
            }
        )
