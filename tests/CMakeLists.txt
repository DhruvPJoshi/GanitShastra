include_directories("${PROJECT_SOURCE_DIR}/include")

set(TEST_SOURCES "${PROJECT_SOURCE_DIR}/tests/main.cpp")
set(TEST_LIBS GanitShastra)

add_executable(main ${TEST_SOURCES})
target_link_libraries(main ${TEST_LIBS})