#!/usr/bin/env bash

mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DSTRUCTURA_STATIC=FALSE
make all
