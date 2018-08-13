# look for custom or system installation of CppUTest
# custom installation check requires prior setup of
# CPPUTEST_HOME environment variable
if(DEFINED ENV{CPPUTEST_HOME})
    message(STATUS "Using CppUTest home: $ENV{CPPUTEST_HOME}")
    set(CPPUTEST_INCLUDE_DIR $ENV{CPPUTEST_HOME}/include)
    set(CPPUTEST_LIBS $ENV{CPPUTEST_HOME}/lib)
    set(CPPUTEST_LDFLAGS CppUTest)
else()
    find_package(PkgConfig REQUIRED)
    pkg_search_module(CPPUTEST REQUIRED cpputest>=3.8)
    message(STATUS "Found cpputest version ${CPPUTEST_VERSION}")
endif()

set(TEST_APP_NAME ${APP_NAME}_test)
set(TEST_SOURCES Vector3Test.cpp AllTests.cpp)

# additional include directories to build test suits
include_directories(${CPPUTEST_INCLUDE_DIR} "${PROJECT_SOURCE_DIR}/include")
link_directories(${CPPUTEST_LIBS})

# create test executable
add_executable(${TEST_APP_NAME} ${TEST_SOURCES})
target_link_libraries(${TEST_APP_NAME} ${APP_NAME} ${CPPUTEST_LDFLAGS})

add_custom_command(TARGET ${TEST_APP_NAME} COMMAND ./${TEST_APP_NAME} POST_BUILD)