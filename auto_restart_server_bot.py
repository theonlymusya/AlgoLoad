#!/usr/bin/env python3
import sys
import time
import subprocess
import os
import logging
from datetime import datetime

# Настройка логирования
logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s - %(levelname)s - %(message)s",
    handlers=[logging.FileHandler("auto_restart.log"), logging.StreamHandler()],
)

# Файл для отслеживания состояния работы скрипта
STATE_FILE = "auto_restart_state.txt"


def write_state(running):
    """Записать состояние работы в файл"""
    with open(STATE_FILE, "w") as f:
        f.write("1" if running else "0")


def read_state():
    """Прочитать состояние работы из файла"""
    try:
        with open(STATE_FILE, "r") as f:
            return f.read().strip() == "1"
    except FileNotFoundError:
        return False


def restart_server():
    """Выполнить команду перезапуска сервера"""
    try:
        subprocess.run(["sh", "./restart_server.sh"], check=True)
        logging.info("Сервер успешно перезапущен")
    except subprocess.CalledProcessError as e:
        logging.error(f"Ошибка при перезапуске сервера: {e}")


def start_auto_restart():
    """Запустить автоматический перезапуск сервера"""
    if read_state():
        logging.warning("Автоматический перезапуск уже запущен")
        return

    write_state(True)
    logging.info("Запущен автоматический перезапуск сервера")

    try:
        while read_state():
            restart_server()
            time.sleep(600)  # 10 минут
    except KeyboardInterrupt:
        stop_auto_restart()


def stop_auto_restart():
    """Остановить автоматический перезапуск сервера"""
    write_state(False)
    logging.info("Автоматический перезапуск сервера остановлен")


def main():
    if len(sys.argv) != 2 or sys.argv[1] not in ["start", "stop"]:
        print("Использование: python3 auto_restart_server_bot.py [start|stop]")
        sys.exit(1)

    command = sys.argv[1]
    if command == "start":
        start_auto_restart()
    else:  # stop
        stop_auto_restart()


if __name__ == "__main__":
    main()
