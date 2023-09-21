cmake_minimum_required(VERSION 3.10)
project(lab_01)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(task_01 task_01.cpp func.cpp)

enable_testing()
add_executable(main main.cpp  func.cpp)
target_link_libraries(main ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND main)