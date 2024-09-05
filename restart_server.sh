pgrep -lf python | awk '{print $1}' | xargs kill -9
sh ./boot2.sh
