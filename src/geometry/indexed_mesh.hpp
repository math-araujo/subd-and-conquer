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
    std::vector<glm::vec3> positions;
    std::vector<std::vector<std::uint32_t>> faces_indices;

    IndexedMesh(std::vector<glm::vec3>&& pos, std::vector<std::vector<std::uint32_t>>&& indices) :
        positions{std::move(pos)}, faces_indices{std::move(indices)}
    {
    }
};

} // namespace geometry

#endif // INDEXED_MESH_HPP