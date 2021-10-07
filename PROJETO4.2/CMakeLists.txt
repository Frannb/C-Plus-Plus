cmake_minimum_required(VERSION 3.14)
project(Prglib)

set(CMAKE_CXX_STANDARD 11)
include_directories(.)
add_executable(Prglib Francin.cpp Diretorio.cpp  prglib.h libs/lista.h libs/lista.cpp)