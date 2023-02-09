cmake_minimum_required(VERSION 3.25)
project(geometry LANGUAGES CXX)

add_library(geometry STATIC
    indexed_mesh.hpp
    io.hpp io.cpp
)

target_compile_features(geometry PRIVATE cxx_std_20)
target_link_libraries(geometry PUBLIC glm::glm tinyobjloader::tinyobjloader)
set_target_properties(geometry PROPERTIES CXX_EXTENSIONS OFF)
target_include_directories(geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})