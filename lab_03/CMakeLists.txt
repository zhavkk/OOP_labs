cmake_minimum_required(VERSION 3.10)
project(oop3)
 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
add_subdirectory(googletest)
 
add_executable(figure main.cpp triangle.cpp square.cpp rectangle.cpp array.cpp)
add_executable(tests tests.cpp triangle.cpp square.cpp rectangle.cpp array.cpp)
 
target_link_libraries(tests PRIVATE GTest::gtest_main)
include(GoogleTest)
 

gtest_discover_tests(tests)
