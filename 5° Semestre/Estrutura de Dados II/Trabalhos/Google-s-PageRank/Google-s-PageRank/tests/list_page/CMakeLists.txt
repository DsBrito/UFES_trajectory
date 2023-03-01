
include_directories(../../)
file(GLOB SOURCES "../../*.c")
list(FILTER SOURCES EXCLUDE REGEX "main.c")
add_executable(testListPage testListPage.c ${SOURCES})
file(COPY index.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME testListPage COMMAND testListPage index.txt WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
