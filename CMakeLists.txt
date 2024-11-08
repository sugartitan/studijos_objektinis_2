cmake_minimum_required(VERSION 3.25)

project(Student_Management_System)
include_directories(Include)
file(GLOB SOURCES "src/*.cpp")

add_executable(Student_Management_System ${SOURCES})