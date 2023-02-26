#ifndef HALFEDGE_HPP
#define HALFEDGE_HPP

#include <memory>

// TODO: maybe implement custom halfedge data structure for learning purposes.
// For now, GeometryCentral provides a fast and easy way to implement subdivision.
// Forward declaration
namespace geometrycentral::surface
{

class ManifoldSurfaceMesh;
class VertexPositionGeometry;

} // namespace geometrycentral::surface

namespace geometry
{

struct Halfedge
{
    std::unique_ptr<geometrycentral::surface::ManifoldSurfaceMesh> mesh{};
    std::unique_ptr<geometrycentral::surface::VertexPositionGeometry> geometry{};

    // Manually declare the constructor and use default on implementation.
    // This is done to allow the forward declaration of GeometryCentral data structures.
    ~Halfedge();
};

} // namespace geometry

#endif // HALFEDGE_HPP