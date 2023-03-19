cmake_minimum_required(VERSION 3.20)
project(NAV)

set(CMAKE_CXX_STANDARD 23)

add_executable(NAV main.cpp utils/config.cpp utils/config.h utils/logging.cpp utils/logging.h)
