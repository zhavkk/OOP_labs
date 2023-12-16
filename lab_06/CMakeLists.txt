cmake_minimum_required(VERSION 3.10)
project(Lab06)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab_06 
    main.cpp
    observer.cpp
    factory.cpp
    NPC.cpp
    dragon.cpp
    druid.cpp
    elf.cpp)

enable_testing()
add_executable(
    tests06
    tests.cpp
    observer.cpp
    factory.cpp
    NPC.cpp
    dragon.cpp
    druid.cpp
    elf.cpp)

target_link_libraries(tests06 ${GTEST_LIBRARIES})

add_test(NAME TESTS COMMAND tests06)