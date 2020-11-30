cmake_minimum_required (VERSION 3.13)
project(ComputerArchitecture)

include_directories(include)

file(GLOB IO "IO/*.cpp")

add_executable(io ${IO})
