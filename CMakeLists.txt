cmake_Minimum_required(VERSION 2.8.3)
#set(project "SCServo")
set(project "test")
project(${project})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

file(GLOB hdrs include/*.h)
file(GLOB srs src/*.cpp)

#add_library(${project} STATIC ${hdrs} ${srs} main.cpp)
add_executable(${project} main.cpp ${hdrs} ${srs} include/Feetech.hpp src/Feetech.cpp include/types.h)