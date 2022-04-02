cmake_minimum_required(VERSION 3.20)
project(untitled17)

set(CMAKE_CXX_STANDARD 17)
find_package(GLEW REQUIRED STATIC)
find_package(GLUT REQUIRED)
find_package(GLM REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(untitled17 main.cpp)

# Add header file
set(GLEW_H /usr/local/Cellar/glew/2.2.0_1/include/GL)
set(GLM_H /usr/local/Cellar/glm/0.9.9.8/include/GL)
include_directories(${GLEW_H} ${GLM_H})

# Add target link
set(GLEW_LINK /usr/local/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.0.dylib)
#set(GLM_LINK /usr/local/Cellar/glm/0.9.9.8/lib/libGLEW.2.2.0.dylib)
link_libraries(${OPENGL} ${GLEW_LINK})

target_link_libraries( ${PROJECT_NAME}
        OpenGL::GL
        GLUT::GLUT
        glm::glm)