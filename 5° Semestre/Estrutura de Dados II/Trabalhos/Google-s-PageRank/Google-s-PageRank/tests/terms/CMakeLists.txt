
include_directories(../../)
file(GLOB SOURCES "../../*.c")
list(FILTER SOURCES EXCLUDE REGEX "main.c")
add_executable(testTerms testTerms.c ${SOURCES})
file(COPY stopwords.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY index.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY pages DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME testTerms COMMAND testTerms index.txt stopwords.txt WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
