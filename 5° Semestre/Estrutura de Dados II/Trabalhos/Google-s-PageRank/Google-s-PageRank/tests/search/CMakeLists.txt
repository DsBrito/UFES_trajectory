find_program (BASH_PROGRAM bash)
if (BASH_PROGRAM)
    message(Diretorios)
    message(${CMAKE_CURRENT_BINARY_DIR})
    message(${CMAKE_BINARY_DIR})
    message(${CMAKE_CURRENT_SOURCE_DIR})
    file(COPY test_search.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
    add_test(scriptTest ${BASH_PROGRAM} test_search.sh)
endif(BASH_PROGRAM)