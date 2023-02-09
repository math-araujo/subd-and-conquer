#include "io.hpp"
#include <exception>
#include <iostream>
#include <tiny_obj_loader.h>

namespace geometry
{

std::vector<IndexedMesh> read_wavefront_file(const std::filesystem::path& filepath)
{
    if (!filepath.has_filename())
    {
        throw std::invalid_argument{"Path must be to a file, not directory"};
    }
    else if (filepath.extension() != ".obj")
    {
        std::cerr << filepath << std::endl;
        throw std::invalid_argument{"File must be Wavefront OBJ"};
    }

    tinyobj::ObjReader reader;
    tinyobj::ObjReaderConfig config;
    config.triangulate = false;
    if (!reader.ParseFromFile(filepath.string(), config))
    {
        if (!reader.Error().empty())
        {
            std::cerr << "TinyObjReader Error: " << reader.Error();
            throw std::runtime_error{""};
        }
    }

    if (!reader.Warning().empty())
    {
        std::cout << "TinyObjReader Warning: " << reader.Warning();
    }

    const auto& attrib = reader.GetAttrib();
    const auto& shapes = reader.GetShapes();

    if (shapes.size() != 1)
    {
        throw std::runtime_error{"Wavefront OBJ file contains more than one mesh; this is not currently supported"};
    }

    std::vector<IndexedMesh> indexed_meshes;
    indexed_meshes.reserve(shapes.size());
    for (const auto& shape : shapes)
    {
        std::vector<glm::vec3> positions;
        positions.reserve(attrib.vertices.size() / 3);
        for (std::size_t i = 0; i < attrib.vertices.size(); i += 3)
        {
            positions.emplace_back(attrib.vertices[i], attrib.vertices[i + 1], attrib.vertices[i + 2]);
        }

        int index_offset{0};
        using FaceIndices = std::vector<std::uint32_t>;
        std::vector<FaceIndices> faces_indices;
        faces_indices.reserve(shape.mesh.num_face_vertices.size());
        for (const std::size_t verts_per_face : shape.mesh.num_face_vertices)
        {
            FaceIndices indices;
            indices.reserve(verts_per_face);
            for (std::size_t vertex_index = 0; vertex_index < verts_per_face; ++vertex_index)
            {
                const tinyobj::index_t index{shape.mesh.indices[index_offset + vertex_index]};
                indices.emplace_back(index.vertex_index);
            }
            faces_indices.emplace_back(std::move(indices));
            index_offset += verts_per_face;
        }

        indexed_meshes.emplace_back(std::move(positions), std::move(faces_indices));
    }

    return indexed_meshes;
}

} // namespace geometry