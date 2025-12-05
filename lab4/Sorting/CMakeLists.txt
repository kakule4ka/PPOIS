cmake_minimum_required(VERSION 3.14)

project(SortingAlgorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Опции для покрытия кода
add_compile_options(--coverage)
add_link_options(--coverage)

find_package(GTest REQUIRED)

# --- Counting Sort Tests ---
add_executable(CountingSortTest 
    CountingSort/CountingSortTest.cpp
)
# Включаем текущую директорию чтобы находить CountingSort.h и Product.h
target_include_directories(CountingSortTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/CountingSort)
target_link_libraries(CountingSortTest PRIVATE GTest::gtest_main)

# --- Insertion Sort Tests ---
add_executable(InsertionSortTest 
    InsertionSort/InsertionSortTest.cpp
)
# Включаем текущую директорию чтобы находить InsertionSort.h и Student.h
target_include_directories(InsertionSortTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/InsertionSort)
target_link_libraries(InsertionSortTest PRIVATE GTest::gtest_main)

# --- Регистрация тестов в CTest ---
include(GoogleTest)
gtest_discover_tests(CountingSortTest)
gtest_discover_tests(InsertionSortTest)

# --- Цель для покрытия (make coverage) ---
find_program(GCOVR_PATH gcovr)

if(GCOVR_PATH)
    add_custom_target(coverage
        # Запуск тестов
        COMMAND ./CountingSortTest
        COMMAND ./InsertionSortTest
        # Генерация отчета (одной строкой)
        COMMAND ${GCOVR_PATH} -r ${CMAKE_SOURCE_DIR} --txt | grep TOTAL
        DEPENDS CountingSortTest InsertionSortTest
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMENT "Running tests and calculating coverage..."
    )
endif()
