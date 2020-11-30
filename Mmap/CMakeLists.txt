cmake_minimum_required (VERSION 3.13)
project(ComputerArchitecture)

include_directories(include)

file(GLOB MMAP "*.cpp")

add_executable(Mmap ${MMAP})