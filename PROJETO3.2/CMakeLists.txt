cmake_minimum_required(VERSION 3.15)
project(Projeto1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projeto1 main.cpp uteis.cpp proj3.h proj3.cpp prglib.h)
target_link_libraries(Projeto1 -L${CMAKE_SOURCE_DIR}/libs prglib)