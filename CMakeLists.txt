cmake_minimum_required(VERSION 3.25)
project(TestingFramework)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        TestingFramework
        main.cpp
        utils/container_operators.h
        testing_tools/assert_equal/assert_equal.h
        testing_tools/assert/assert.h
)
