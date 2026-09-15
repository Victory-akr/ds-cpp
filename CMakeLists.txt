cmake_minimum_required(VERSION 3.16)
project(ds_cpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra)

# 说明：命令行/CI 用 Makefile，CLion 用这个 CMakeLists —— 两者指向同一套 src/ 和 tests/
# 实现文件（不含带 main() 的 src/main.cpp）
file(GLOB LIB_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
list(REMOVE_ITEM LIB_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_executable(ds_cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${LIB_SOURCES})
target_include_directories(ds_cpp PRIVATE include)

# 每个 tests/*.cpp 编译成一个测试可执行文件，并注册到 CTest
enable_testing()
file(GLOB TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
foreach(test_src ${TEST_SOURCES})
  get_filename_component(test_name ${test_src} NAME_WE)
  add_executable(${test_name} ${test_src} ${LIB_SOURCES})
  target_include_directories(${test_name} PRIVATE include)
  add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()
