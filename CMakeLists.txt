cmake_minimum_required(VERSION 3.21)
project(THE_MAP)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

setup_geode_mod(${PROJECT_NAME})
