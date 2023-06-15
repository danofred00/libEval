
set(CLI_OUTPUT_FILENAME "evald")

set(SOURCES 
    main.cpp)

add_definitions(-DPROJECT_DESCRIPTION="${PROJECT_DESCRIPTION}")

add_executable(${CLI_OUTPUT_FILENAME} ${SOURCES})
target_include_directories(${CLI_OUTPUT_FILENAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${CLI_OUTPUT_FILENAME} ${LIBNAME})
