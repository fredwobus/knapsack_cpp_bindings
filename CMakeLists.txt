cmake_minimum_required(VERSION 3.21)

project(
  libknapsack
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(knapsack SHARED knapsack.cpp knapsack.hpp)
set_target_properties(knapsack PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(knapsack PROPERTIES PUBLIC_HEADER knapsack.hpp)
target_include_directories(knapsack PRIVATE .)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(run_knapsack run_knapsack.cpp)
target_link_libraries(run_knapsack PRIVATE knapsack)

add_subdirectory(pybind11)
pybind11_add_module(pyknapsack pyknapsack.cpp)
target_link_libraries(pyknapsack PRIVATE knapsack)
