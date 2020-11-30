cmake_minimum_required (VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)
project(ComputerArchitecture)

include_directories(include)

file(GLOB IO "*.cpp")

add_executable(io ${IO})
