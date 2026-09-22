cmake_minimum_required(VERSION 3.16)

project(adaptive_set_engine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(adaptive_set src/adaptive_set.cpp)
target_include_directories(adaptive_set PUBLIC include)

add_executable(adaptive_set_example example/main.cpp)
target_link_libraries(adaptive_set_example PRIVATE adaptive_set)
