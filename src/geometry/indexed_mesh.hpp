#ifndef INDEXED_MESH_HPP
#define INDEXED_MESH_HPP

#include "halfedge.hpp"
#include <glm/vec3.hpp>
#include <memory>
#include <tuple>
#include <vector>

namespace geometry
{

/*
Botsch et al also calls this data structure as "indexed face set".
Faces indices follow a counter-clockwise winding order.
*/
struct IndexedMesh
{
    std::vector<std::vector<std::size_t>> faces_indices;
    std::vector<glm::vec3> positions;

    IndexedMesh(std::vector<std::vector<std::size_t>>&& indices, std::vector<glm::vec3>&& pos) :
        faces_indices{std::move(indices)}, positions{std::move(pos)}
    {
    }
};

Halfedge to_halfedge(const IndexedMesh& indexed_mesh);

} // namespace geometry

#endif // INDEXED_MESH_HPP