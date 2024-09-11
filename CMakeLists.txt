cmake_minimum_required(VERSION 3.5)
project("trio-lang")

add_executable(${PROJECT_NAME} src/Main.c)

target_include_directories(${CMAKE_PROJECT_NAME} src/trio)