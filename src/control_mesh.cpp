#include "control_mesh.hpp"
#include "geometry/indexed_mesh.hpp"
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

namespace app
{

ControlMesh::ControlMesh(const geometry::IndexedMesh& indexed_mesh) :
    number_of_vertices_{static_cast<int>(indexed_mesh.positions.size())}
{
    glCreateVertexArrays(1, &vertex_array_id_);
    glBindVertexArray(vertex_array_id_);

    glGenBuffers(1, &vertex_buffer_id_);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_id_);
    glBufferData(GL_ARRAY_BUFFER, indexed_mesh.positions.size() * 3 * sizeof(float),
                 static_cast<const float*>(glm::value_ptr(indexed_mesh.positions.front())), GL_STATIC_DRAW);

    // Gather indices
    std::vector<std::uint32_t> edge_indices;
    for (auto& face : indexed_mesh.faces_indices)
    {
        for (std::size_t i = 0; i < face.size(); ++i)
        {
            edge_indices.emplace_back(face[i]);
            edge_indices.emplace_back(face[(i + 1) % face.size()]);
        }
    }
    number_of_edges_ = edge_indices.size();
    glGenBuffers(1, &element_buffer_id_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_id_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, edge_indices.size() * sizeof(std::uint32_t), edge_indices.data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glEnableVertexAttribArray(0);
}

ControlMesh::ControlMesh(ControlMesh&& other) noexcept :
    number_of_edges_{other.number_of_edges_}, number_of_vertices_{other.number_of_vertices_},
    vertex_array_id_{other.vertex_array_id_}, vertex_buffer_id_{other.vertex_buffer_id_}, element_buffer_id_{
                                                                                              other.element_buffer_id_}
{
    other.number_of_edges_ = other.number_of_vertices_ = other.vertex_array_id_ = other.vertex_buffer_id_ =
        other.element_buffer_id_ = 0;
}

ControlMesh& ControlMesh::operator=(ControlMesh&& other) noexcept
{
    std::swap(number_of_edges_, other.number_of_edges_);
    std::swap(number_of_vertices_, other.number_of_vertices_);
    std::swap(vertex_array_id_, other.vertex_array_id_);
    std::swap(vertex_buffer_id_, other.vertex_buffer_id_);
    std::swap(element_buffer_id_, other.element_buffer_id_);
    return *this;
}

ControlMesh::~ControlMesh()
{
    glDeleteBuffers(1, &element_buffer_id_);
    glDeleteBuffers(1, &vertex_buffer_id_);
    glDeleteBuffers(1, &vertex_array_id_);
}

void ControlMesh::bind()
{
    glBindVertexArray(vertex_array_id_);
}

void ControlMesh::render()
{
    bind();
    glDrawElements(GL_LINES, 2 * number_of_edges_, GL_UNSIGNED_INT, 0);
    glPointSize(20.0f);
    glDrawArrays(GL_POINTS, 0, number_of_vertices_);
    glPointSize(1.0f);
}

} // namespace app