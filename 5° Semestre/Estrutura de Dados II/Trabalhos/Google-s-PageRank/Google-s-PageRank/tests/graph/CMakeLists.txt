
include_directories(../../)
file(GLOB SOURCES "../../*.c")
list(FILTER SOURCES EXCLUDE REGEX "main.c")
add_executable(testGraph testGraph.c ${SOURCES})
file(COPY graph.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME testGraph COMMAND testGraph graph.txt WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
