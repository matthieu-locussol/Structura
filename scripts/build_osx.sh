#!/usr/bin/env bash

mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DSTRUCTURA_TESTS=ON
cmake --build . --config "Debug"