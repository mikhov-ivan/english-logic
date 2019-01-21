cmake_minimum_required(VERSION 2.8.12)
project(english_logic)

set(english_logic_VERSION_MAJOR 1)
set(english_logic_VERSION_MINOR 0)

configure_file(
    "${PROJECT_SOURCE_DIR}/EnglishLogicConfig.hpp.in"
    "${PROJECT_SOURCE_DIR}/include/EnglishLogicConfig.hpp"
)

include_directories("include")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -pedantic -Wall")
set(SRC_LIST "src/main.cpp" "src/String.cpp" "src/Record.cpp" "src/Logger.cpp")

add_executable(${PROJECT_NAME} ${SRC_LIST})
