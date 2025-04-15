#!/bin/bash

# Включаем режим прерывания при ошибках
set -e

# Создаем директорию для логов, если она не существует
mkdir -p logs

# Функция для логирования
log() {
    echo "$(date '+%Y-%m-%d %H:%M:%S') - $1" >> logs/auto_restart.log
}

# Функция для перезапуска сервера с обработкой ошибок
restart_server() {
    if sh ./restart_server.sh > /dev/null 2>&1; then
        log "Перезапуск сервера выполнен успешно"
    else
        log "Ошибка при перезапуске сервера (код: $?), но продолжаем работу"
    fi
}

# Функции обработки сигналов
sigterm_handler() {
    log "Скрипт автоперезапуска получил сигнал SIGTERM"
    exit 0
}

sigint_handler() {
    log "Скрипт автоперезапуска получил сигнал SIGINT"
    exit 0
}

sighup_handler() {
    log "Скрипт автоперезапуска получил сигнал SIGHUP"
    exit 0
}

# Установка обработчиков всех возможных сигналов завершения
trap sigterm_handler SIGTERM
trap sigint_handler SIGINT
trap sighup_handler SIGHUP

# Логируем запуск скрипта
log "Скрипт автоперезапуска запущен (PID: $$)"

# Бесконечный цикл
while true; do
    # Перезапускаем сервер с обработкой ошибок
    log "Выполняется перезапуск сервера"
    restart_server
    
    # Ждем 10 минут
    sleep 600 || {
        log "Прерывание sleep, продолжаем работу"
        continue
    }
done
