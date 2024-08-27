# AlgoLoad

## Building and running AlgoLoad Docker with Makefile

```sh
make build run    # first build and run
make              # all subsequent builds
```

## Building and running AlgoLoad Docker without Makefile

```sh
docker build -t container_name .
docker run -p 3001:3001 -v $(pwd)/volume:/home/flask_skipod/volume container_name:latest
```

<http://localhost:3001/>

k000 CcXK9ha00rcw
