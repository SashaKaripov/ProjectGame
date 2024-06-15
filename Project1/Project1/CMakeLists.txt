cmake_minimum_required(VERSION 3.10.0)
project(Project1)
add_executable(tests functions.h tests.cpp)
target_link_libraries(tests PUBLIC doctest)
add_test(NAME tests COMMAND tests --force-colors -d)


enable_testing()
add_subdirectory(external/doctest)
