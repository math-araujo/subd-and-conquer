cmake_minimum_required(VERSION 3.25)
project(geometry LANGUAGES CXX)

add_library(geometry INTERFACE
    indexed_mesh.hpp
)

target_link_libraries(geometry INTERFACE glm::glm tinyobjloader::tinyobjloader)
set_target_properties(geometry PROPERTIES CXX_EXTENSIONS OFF)
target_include_directories(geometry INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})