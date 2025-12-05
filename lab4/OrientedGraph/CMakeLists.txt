cmake_minimum_required(VERSION 3.14)
project(OrientedGraphSimple LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Флаги покрытия
add_compile_options(--coverage)
add_link_options(--coverage)

find_package(GTest REQUIRED)

add_executable(OrientedGraphTest OrientedGraphTest.cpp)
target_include_directories(OrientedGraphTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(OrientedGraphTest PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(OrientedGraphTest)

find_program(GCOVR_PATH gcovr)
if(GCOVR_PATH)
    add_custom_target(coverage
        COMMAND ./OrientedGraphTest
        COMMAND ${GCOVR_PATH} -r ${CMAKE_SOURCE_DIR} --txt | grep TOTAL
        DEPENDS OrientedGraphTest
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()
