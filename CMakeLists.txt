cmake_minimum_required(VERSION 3.10)
project(vector_lib VERSION 1.0.0 LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 17)

# collect all source files
file(GLOB sources src/*.cpp)
list(APPEND sources main.cpp)
message("${sources}")
set(SOURCES ${sources})

# build exectutable
add_executable(${PROJECT_NAME} ${WIN32_GUI} ${SOURCES})
target_compile_options(${PROJECT_NAME} PUBLIC -lm -Wall)
target_include_directories(${PROJECT_NAME} PRIVATE "include")
