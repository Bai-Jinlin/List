cmake_minimum_required(VERSION 3.9)
project(functional)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES list_example.cpp)

add_executable(functional ${SOURCE_FILES})
#add_executable(sample_formats format.cpp)