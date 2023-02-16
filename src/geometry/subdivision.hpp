#ifndef SUBDIVISION_HPP
#define SUBDIVISION_HPP

#include "geometrycentral/surface/manifold_surface_mesh.h"
#include "geometrycentral/surface/vertex_position_geometry.h"

namespace geometry
{

using MeshAndGeometry = std::tuple<std::unique_ptr<geometrycentral::surface::ManifoldSurfaceMesh>,
                                   std::unique_ptr<geometrycentral::surface::VertexPositionGeometry>>;

MeshAndGeometry catmull_clark_subdivision(std::unique_ptr<geometrycentral::surface::ManifoldSurfaceMesh> mesh,
                                          std::unique_ptr<geometrycentral::surface::VertexPositionGeometry> geometry);

} // namespace geometry

#endif // SUBDIVISION_HPP