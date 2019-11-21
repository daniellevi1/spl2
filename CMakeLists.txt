cmake_minimum_required(VERSION 3.15)
project(Test55)

set(CMAKE_CXX_STANDARD 11)

add_executable(Test55 src/Main.cpp src/Action.cpp src/Session.cpp src/Watchable.cpp)