# CMake generated Testfile for 
# Source directory: D:/Users/AIZakharov/Documents/GitHub/STL_practice/tests/unit_tests
# Build directory: D:/Users/AIZakharov/Documents/GitHub/STL_practice/cmake_build/tests/UT_DIRECTORY
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(unit_tests "D:/Users/AIZakharov/Documents/GitHub/STL_practice/build/bin/Debug/unit_tests.exe")
  set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "D:/Users/AIZakharov/Documents/GitHub/STL_practice/tests/cmake_modules/AddGTestTest.cmake;18;add_test;D:/Users/AIZakharov/Documents/GitHub/STL_practice/tests/unit_tests/CMakeLists.txt;25;add_gtest_test;D:/Users/AIZakharov/Documents/GitHub/STL_practice/tests/unit_tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(unit_tests "D:/Users/AIZakharov/Documents/GitHub/STL_practice/build/bin/Release/unit_tests.exe")
  set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "D:/Users/AIZakharov/Documents/GitHub/STL_practice/tests/cmake_modules/AddGTestTest.cmake;18;add_test;D:/Users/AIZakharov/Documents/GitHub/STL_practice/tests/unit_tests/CMakeLists.txt;25;add_gtest_test;D:/Users/AIZakharov/Documents/GitHub/STL_practice/tests/unit_tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(unit_tests "D:/Users/AIZakharov/Documents/GitHub/STL_practice/build/bin/MinSizeRel/unit_tests.exe")
  set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "D:/Users/AIZakharov/Documents/GitHub/STL_practice/tests/cmake_modules/AddGTestTest.cmake;18;add_test;D:/Users/AIZakharov/Documents/GitHub/STL_practice/tests/unit_tests/CMakeLists.txt;25;add_gtest_test;D:/Users/AIZakharov/Documents/GitHub/STL_practice/tests/unit_tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(unit_tests "D:/Users/AIZakharov/Documents/GitHub/STL_practice/build/bin/RelWithDebInfo/unit_tests.exe")
  set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "D:/Users/AIZakharov/Documents/GitHub/STL_practice/tests/cmake_modules/AddGTestTest.cmake;18;add_test;D:/Users/AIZakharov/Documents/GitHub/STL_practice/tests/unit_tests/CMakeLists.txt;25;add_gtest_test;D:/Users/AIZakharov/Documents/GitHub/STL_practice/tests/unit_tests/CMakeLists.txt;0;")
else()
  add_test(unit_tests NOT_AVAILABLE)
endif()
