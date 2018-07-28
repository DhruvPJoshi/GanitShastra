cmake_minimum_required(VERSION 3.5)

project(GanitShastra)

set(GANIT_SHASTRA_VERSION_MAJOR 0)
set(GANIT_SHASTRA_VERSION_MINOR 1)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/include")
add_library(GanitShastra STATIC ${SOURCES})

add_subdirectory(tests)