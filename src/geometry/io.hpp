#ifndef GEOMETRY_IO_HPP
#define GEOMETRY_IO_HPP

#include <filesystem>
#include <vector>

#include "indexed_mesh.hpp"

namespace geometry
{

/*
Reads a polygon (not necessarily triangle) mesh from a Wavefront OBJ file.
If the file provided is not a Waverfront OBJ file, an exception is throw.
*/
std::vector<IndexedMesh> read_wavefront_file(const std::filesystem::path& filepath);

} // namespace geometry

#endif // GEOMETRY_IO_HPP