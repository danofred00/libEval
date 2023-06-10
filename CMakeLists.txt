cmake_minimum_required(VERSION 3.2)

project(libCalc LANGUAGES CXX)

set(PROJECT_VERSION 1.0)
set(PROJECT_DESCRIPTION "A lib to automate arithmetic operations")

set(SOURCES
    ${CMAKE_SOURCE_DIR}/lib/calculator.cpp)

add_library(calc STATIC ${SOURCES})

target_include_directories(calc PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(tests)