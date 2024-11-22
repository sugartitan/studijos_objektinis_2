cmake_minimum_required(VERSION 3.25)

set(CXXFLAGS "-O1")
set(CMAKE_CXX_FLAGS "${CXXFLAGS}")

project(Student_Management_System)
include_directories(Include)
file(GLOB SOURCES "src/*.cpp")

add_executable(Student_Management_System ${SOURCES})