# cmake_minimum_required(VERSION 3.10)
# project(lab_02)

# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_executable(tests tests.cpp Eleven.cpp)

# enable_testing()
# add_executable(main main.cpp  Eleven.cpp)
# target_link_libraries(main ${GTEST_LIBRARIES})

# add_test(NAME BASIC COMMAND main)
cmake_minimum_required(VERSION 3.10)
project(oop2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)

add_executable(tests tests.cpp Eleven.cpp)
add_executable(main main.cpp Eleven.cpp)

target_link_libraries(tests PRIVATE GTest::gtest_main)
include(GoogleTest)



gtest_discover_tests(tests)