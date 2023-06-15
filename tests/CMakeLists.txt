

enable_testing(true)

set(TestFiles 
    test.cpp)

add_executable(test ${TestFiles})
target_include_directories(test PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(test ${LIBNAME} )

#foreach(testcase ${TestFiles})

#    string(FIND "${testcase}" "." limiter)
#    string(SUBSTRING "${testcase}" 0 ${limiter} output)

#    message("Configure TestCase : ${testcase}")
#    add_executable(${output} ${CMAKE_CURRENT_SOURCE_DIR}/${estcase})
#    add_test(NAME ${output} COMMAND ${output})

#    target_include_directories(${output} PRIVATE ${CMAKE_SOURCE_DIR}/include)
#    target_link_libraries(${output} calc)

#endforeach()
