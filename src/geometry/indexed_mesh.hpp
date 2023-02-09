#ifndef INDEXED_MESH_HPP
#define INDEXED_MESH_HPP

#include <cstdint>
#include <glm/vec3.hpp>
#include <vector>

namespace geometry
{

/*
Botsch et al also calls this data structure as "indexed face set".
*/
struct IndexedMesh
{
    std::vector<glm::vec3> vertices;
    std::vector<std::vector<std::uint32_t>> indices;
};

} // namespace geometry

#endif // INDEXED_MESH_HPP