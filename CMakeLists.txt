cmake_minimum_required(VERSION 3.2)

project(libCalc LANGUAGES CXX)

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

set(SOURCES
    ${CMAKE_SOURCE_DIR}/lib/eval.cpp)

file(GLOB_RECURSE HEADERS 
     ${CMAKE_SOURCE_DIR}/include/ *.h)

add_library(${LIBNAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${LIBNAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(cli)
add_subdirectory(tests)

# install the client and the lib
install(
    TARGETS ${LIBNAME}
    ARCHIVE
        DESTINATION ${CMAKE_INSTALL_LIBDIR})

# install headers
install(FILES ${HEADERS} 
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/eval)