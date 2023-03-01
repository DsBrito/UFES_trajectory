cmake_minimum_required(VERSION 3.13) 
project(trab3 C)
set(C_STANDARD  11)
add_compile_options(-Wno-discarded-qualifiers)

include_directories(.)
file(GLOB SOURCES "*.c")

add_executable(trab3 ${SOURCES})

enable_testing()
add_subdirectory(tests/stop_words)
add_subdirectory(tests/list_page)
add_subdirectory(tests/terms)
add_subdirectory(tests/graph)
add_subdirectory(tests/calc)
add_subdirectory(tests/search)
add_subdirectory(tests/pr_sort)
