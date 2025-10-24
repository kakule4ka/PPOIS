cmake_minimum_required(VERSION 3.16)
project(BigIntProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g")
set(CMAKE_BUILD_TYPE Debug)

find_package(GTest REQUIRED)
message(STATUS "Found GTest version: ${GTEST_VERSION}")

add_library(bigint_lib BigInt.cpp)
target_include_directories(bigint_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(bigint_tests BigIntTest.cpp)
target_link_libraries(bigint_tests bigint_lib GTest::gtest GTest::gtest_main pthread)

enable_testing()
add_test(NAME BigIntUnitTests COMMAND bigint_tests)

add_custom_target(run_bigint_tests
    COMMAND ./bigint_tests
    DEPENDS bigint_tests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running BigInt tests..."
)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    add_executable(bigint_app main.cpp)
    target_link_libraries(bigint_app bigint_lib)
endif()

message(STATUS "BigInt project configured successfully")
message(STATUS "Source files: BigInt.h, BigInt.cpp, BigIntTest.cpp")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")