cmake_minimum_required(VERSION 3.15)

project(glad LANGUAGES C)
set(C_STANDARD 11)
set(C_STANDARD_REQUIRED ON)

file(GLOB sources src/*.c)


add_library(${PROJECT_NAME} ${sources})
target_include_directories(${PROJECT_NAME} PUBLIC "include")