cmake_minimum_required(VERSION 3.15)
project(TriangleProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

add_subdirectory(external/glfw)

add_library(glad external/glad/src/glad.c)

target_include_directories(glad PUBLIC external/glad/include)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(TriangleProject ${SRC_FILES})

target_include_directories(TriangleProject PRIVATE
    src
    external/glad/include
    external/glfw/include
    external/glm
)

target_link_libraries(TriangleProject
    glfw
    glad
    OpenGL::GL
)
