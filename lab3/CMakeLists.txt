cmake_minimum_required(VERSION 3.16)
project(ConstructionCompany)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Флаги для покрытия — применяем глобально к проекту
if(CMAKE_BUILD_TYPE STREQUAL "Coverage" OR CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} --coverage")
endif()

include_directories(include)

find_package(GTest REQUIRED)

# Сбор всех исходников
file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS "src/core/*.cpp")
file(GLOB_RECURSE MODEL_SOURCES CONFIGURE_DEPENDS "src/models/*.cpp")
file(GLOB_RECURSE SERVICE_SOURCES CONFIGURE_DEPENDS "src/services/*.cpp")
file(GLOB_RECURSE EXCEPTION_SOURCES CONFIGURE_DEPENDS "src/exceptions/*.cpp")

# Библиотека (без дублирования флагов — они уже глобальные)
add_library(construction_company STATIC
    ${CORE_SOURCES}
    ${MODEL_SOURCES}
    ${SERVICE_SOURCES}
    ${EXCEPTION_SOURCES}
)

# Тесты
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "tests/*.cpp")
add_executable(run_tests ${TEST_SOURCES})

# Важно: линкуем с библиотекой И применяем те же флаги покрытия
target_link_libraries(run_tests construction_company GTest::gtest GTest::gtest_main)

# Гарантируем, что run_tests тоже получает флаги покрытия (на случай, если не сработало глобально)
if(CMAKE_BUILD_TYPE STREQUAL "Coverage" OR CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(run_tests PRIVATE --coverage)
    target_link_options(run_tests PRIVATE --coverage)
endif()

enable_testing()
add_test(NAME run_tests COMMAND run_tests)
