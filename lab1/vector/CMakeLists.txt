cmake_minimum_required(VERSION 3.16)
project(VectorProject CXX)

# Настройки компилятора
set(CMAKE_CXX_STANDARD 17)  # Ты используешь g++ 13.3, можно использовать C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Флаги компиляции
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g")
set(CMAKE_BUILD_TYPE Debug)

# Поиск Google Test (у тебя версия 1.14.0)
find_package(GTest REQUIRED)
message(STATUS "Found GTest version: ${GTEST_VERSION}")

# Основная библиотека вектора
add_library(vector_lib vector.cpp)
target_include_directories(vector_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(vector_lib PRIVATE cxx_std_17)

# Исполняемый файл с тестами
add_executable(vector_tests vector_gtest.cpp)
target_include_directories(vector_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(vector_tests vector_lib GTest::gtest GTest::gtest_main)
target_compile_features(vector_tests PRIVATE cxx_std_17)

# Основное приложение (если нужно)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/main" AND NOT IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/main")
    add_executable(main_app main)
    target_link_libraries(main_app vector_lib)
    target_compile_features(main_app PRIVATE cxx_std_17)
endif()

# Настройка тестов
enable_testing()
add_test(NAME VectorUnitTests COMMAND vector_tests)

# Полезные цели
add_custom_target(run_tests
    COMMAND ./vector_tests
    DEPENDS vector_tests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running vector tests..."
)