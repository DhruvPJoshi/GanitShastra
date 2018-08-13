cmake_minimum_required(VERSION 3.5)

# basic project setup
set(GANIT_SHASTRA_VERSION_MAJOR 0)
set(GANIT_SHASTRA_VERSION_MINOR 1)
set(APP_NAME GanitShastra)

project(${APP_NAME})

# additional compiler flags
add_compile_options(-std=c++11)

# headers and sources search directories
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
include_directories("${PROJECT_SOURCE_DIR}/include")

# lib setup
add_library(${APP_NAME} STATIC ${SOURCES})

# build tests, optional
option(COMPILE_TESTS "Compile the tests" OFF)
if(COMPILE_TESTS)
    add_subdirectory(tests)
endif(COMPILE_TESTS)