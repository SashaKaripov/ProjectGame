# CMake generated Testfile for 
# Source directory: C:/Users/bonis/source/repos/Project1/Project1
# Build directory: C:/Users/bonis/source/repos/Project1/Project1/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(tests "C:/Users/bonis/source/repos/Project1/Project1/build/tests.exe" "--force-colors" "-d")
set_tests_properties(tests PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/bonis/source/repos/Project1/Project1/CMakeLists.txt;5;add_test;C:/Users/bonis/source/repos/Project1/Project1/CMakeLists.txt;0;")
subdirs("external/doctest")
