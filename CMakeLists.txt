cmake_minimum_required(VERSION 3.30)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib/glad)
add_subdirectory(lib/glfw)
add_subdirectory(lib/fmt)

add_executable(OpengGL main.cpp)
target_link_libraries(OpengGL PRIVATE glad glfw fmt)