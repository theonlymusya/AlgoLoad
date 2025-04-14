#!/bin/bash

# Функция для логирования
log() {
    echo "$(date '+%Y-%m-%d %H:%M:%S') - $1" >> logs/auto_restart.log
}

# Поиск PID процесса start_auto_restart_server.sh
PID=$(pgrep -f "start_auto_restart_server.sh")

if [ -z "$PID" ]; then
    log "Процесс автоперезапуска не найден"
    echo "Процесс автоперезапуска не найден"
    exit 1
fi

# Отправляем сигнал SIGTERM для корректного завершения
kill -TERM $PID

# Ждем завершения процесса (максимум 5 секунд)
for i in {1..5}; do
    if ! ps -p $PID > /dev/null; then
        log "Процесс автоперезапуска успешно остановлен"
        echo "Процесс автоперезапуска успешно остановлен"
        exit 0
    fi
    sleep 1
done

# Если процесс все еще работает, завершаем принудительно
if ps -p $PID > /dev/null; then
    kill -9 $PID
    log "Процесс автоперезапуска принудительно остановлен"
    echo "Процесс автоперезапуска принудительно остановлен"
fi