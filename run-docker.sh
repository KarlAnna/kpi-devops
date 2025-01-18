#!/bin/bash

IMAGE_NAME="http-server-expseries"

docker build --no-cache -t $IMAGE_NAME .

docker run -d --name expseries-backend -p 8081:8081 $IMAGE_NAME
