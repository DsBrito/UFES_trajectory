
include_directories(../../)
file(GLOB SOURCES "../../*.c")
list(FILTER SOURCES EXCLUDE REGEX "main.c")
add_executable(testStopWords testStopWords.c ${SOURCES})
file(COPY stopwords.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME testStopWords COMMAND testStopWords stopwords.txt WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
