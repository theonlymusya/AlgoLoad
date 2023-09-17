# AlgoLoad

## Building AlgoLoad

```sh
docker build -t container_name .
```

## Runing AlgoLoad
```sh
docker run -p 3001:3001 -v $(pwd)/volume:/home/flask_skipod/volume container_name:latest
```