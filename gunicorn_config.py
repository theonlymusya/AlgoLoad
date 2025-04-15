import multiprocessing

workers = multiprocessing.cpu_count() * 2 + 1
threads = 2
worker_class = "gthread"
timeout = 300
keepalive = 120
max_requests = 100
max_requests_jitter = 10

bind = "0.0.0.0:3001"
umask = 0o007
reload = True

# logging
accesslog = "logs/microbial.log"
errorlog = "logs/microbial.log"
loglevel = "info"
capture_output = True
enable_stdio_inheritance = True
