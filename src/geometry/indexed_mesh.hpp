#ifndef INDEXED_MESH_HPP
#define INDEXED_MESH_HPP

#include <cstdint>
#include <glm/vec3.hpp>
#include <vector>

namespace geometry
{

/*
Botsch et al also calls this data structure as "indexed face set".
Faces indices follow a counter-clockwise winding order.
*/
struct IndexedMesh
{
    std::vector<std::vector<std::uint32_t>> faces_indices;
    std::vector<glm::vec3> positions;

    IndexedMesh(std::vector<std::vector<std::uint32_t>>&& indices, std::vector<glm::vec3>&& pos) :
        faces_indices{std::move(indices)}, positions{std::move(pos)}
    {
    }
};

} // namespace geometry

#endif // INDEXED_MESH_HPP