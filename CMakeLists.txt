cmake_minimum_required(VERSION 3.2)

project(libCalc LANGUAGES CXX)

set(PROJECT_VERSION 1.0.0)
set(PROJECT_DESCRIPTION "A tool to evaluate arithmetic expressions.")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# some constants
set(LIBNAME "calc")

# generations
configure_file(
    ${CMAKE_SOURCE_DIR}/version.h.in # input file
    ${CMAKE_SOURCE_DIR}/include/version.h # output file
    USE_SOURCE_PERMISSIONS)

set(SOURCES
    ${CMAKE_SOURCE_DIR}/lib/evaluator.cpp)

add_library(${LIBNAME} STATIC ${SOURCES})

target_include_directories(${LIBNAME}  PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(cli)
add_subdirectory(tests)