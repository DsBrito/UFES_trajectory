
include_directories(../../)
file(GLOB SOURCES "../../*.c")
list(FILTER SOURCES EXCLUDE REGEX "main.c")
add_executable(testPRSort testPRSort.c ${SOURCES})

add_test(NAME testPRSort COMMAND testPRSort ./../../../example2/ WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
