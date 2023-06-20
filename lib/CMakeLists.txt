

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/eval.cpp)

file(GLOB_RECURSE HEADERS 
    ${CMAKE_SOURCE_DIR}/include/ *.h)

# create the lib
add_library(${LIBNAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${LIBNAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# install the client and the lib
install(
    TARGETS ${LIBNAME}
    ARCHIVE
        DESTINATION ${CMAKE_INSTALL_LIBDIR})

# install headers
install(FILES ${HEADERS} 
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/eval)