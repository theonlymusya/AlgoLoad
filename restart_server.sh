# old kill command
# pgrep -lf python | awk '{print $1}' | xargs kill -9

# Находим и завершаем процесс на порту 3001
lsof -ti:3001 | xargs kill -9 2>/dev/null || true

# Запускаем новый сервер
sh ./boot2.sh
