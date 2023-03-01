
include_directories(../../)
file(GLOB SOURCES "../../*.c")
list(FILTER SOURCES EXCLUDE REGEX "main.c")
add_executable(testCalc testCalc.c ${SOURCES})
file(COPY graph.txt index.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
#file(COPY index.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME testCalc COMMAND testCalc index.txt graph.txt WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
