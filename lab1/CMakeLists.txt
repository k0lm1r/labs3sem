cmake_minimum_required(VERSION 3.10.0)
project(lab LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")
endif()

add_executable(${PROJECT_NAME} main.cpp Matrix/Matrix.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE Matrix)