cmake_minimum_required(VERSION 3.2)

project(libEval LANGUAGES CXX)

set(PROJECT_VERSION 1.0.0)
set(PROJECT_DESCRIPTION "A tool to evaluate arithmetic expressions.")
set(PROJECT_HOMEPAGE_URL "https://github.com/danofred00/libeval.git")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# includes
include(GNUInstallDirs)

# some constants
set(LIBNAME "eval")

# generations
configure_file(
    ${CMAKE_SOURCE_DIR}/version.h.in # input file
    ${CMAKE_SOURCE_DIR}/include/eval/version.h # output file
    USE_SOURCE_PERMISSIONS)

add_subdirectory(lib)
add_subdirectory(cli)
add_subdirectory(tests)

