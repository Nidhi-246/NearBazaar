# algo-service

## Setup
mkdir include
curl -L -o include/httplib.h https://raw.githubusercontent.com/yhirose/cpp-httplib/master/httplib.h
curl -L -o include/json.hpp https://raw.githubusercontent.com/nlohmann/json/develop/single_include/nlohmann/json.hpp

## Build
mkdir build && cd build
cmake -G "MinGW Makefiles" ..
mingw32-make

## Run
./server.exe   (then open http://localhost:8080/autocomplete?q=a4)