cmake_minimum_required(VERSION 3.20)
project(untitled17)

set(CMAKE_CXX_STANDARD 17)
find_package(GLEW REQUIRED STATIC)
find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(untitled17 main.cpp)

target_link_libraries( ${PROJECT_NAME}
        OpenGL::GL
        GLUT::GLUT)