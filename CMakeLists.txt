cmake_minimum_required(VERSION 3.10)
project(TheAlarmingSystem)

set(CMAKE_CXX_STANDARD 14)

include_directories(c++)
include_directories(src)

file(GLOB src_folder
        "src/*.cc" )

add_executable(TheAlarmingSystem c++/pump.cc c++/runtime.cc ${src_folder} src/main.cpp)

target_link_libraries(TheAlarmingSystem pthread)