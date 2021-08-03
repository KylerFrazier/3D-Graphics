cmake_minimum_required(VERSION 3.0)

set(EXEC_NAME render)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 ")

project(3D_graphics)

add_executable(
    ${EXEC_NAME}
    main.cpp
    Renderable.hpp
    Renderable.cpp
    Vector3.hpp
    Vector3.cpp
    Cube.hpp
    Cube.cpp
    Renderer.hpp
    Renderer.cpp
)

if (POLICY CMP0072)
    cmake_policy (SET CMP0072 NEW)
endif (POLICY CMP0072)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(${EXEC_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )