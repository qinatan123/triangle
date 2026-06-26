cmake_minimum_required(VERSION 3.15)
project(TriangleProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_library(glad external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

file(GLOB_RECURSE SRC_FILES src/**/*.cpp src/*.cpp)

add_executable(TriangleProject main.cpp ${SRC_FILES})

target_include_directories(TriangleProject PRIVATE
    src
    external/glad/include
)

target_link_libraries(TriangleProject
    glfw
    glad
    OpenGL::GL
    glm::glm
)
