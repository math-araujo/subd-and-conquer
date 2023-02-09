#ifndef CONTROL_MESH_HPP
#define CONTROL_MESH_HPP

#include <cstdint>

// Forward Declaration
namespace geometry
{

struct IndexedMesh;

} // namespace geometry

namespace app
{

class ControlMesh
{
public:
    ControlMesh(const geometry::IndexedMesh& indexed_mesh);
    ControlMesh(const ControlMesh&) = delete;
    ControlMesh(ControlMesh&& other) noexcept;
    ControlMesh& operator=(const ControlMesh&) = delete;
    ControlMesh& operator=(ControlMesh&& other) noexcept;
    ~ControlMesh();

    void bind();
    void render();

private:
    int number_of_edges_{0};
    int number_of_vertices_{0};
    std::uint32_t vertex_array_id_{0};
    std::uint32_t vertex_buffer_id_{0};
    std::uint32_t element_buffer_id_{0};
};

} // namespace app

#endif // CONTROL_MESH_HPP