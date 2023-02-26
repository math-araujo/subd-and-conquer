#ifndef SUBDIVISION_HPP
#define SUBDIVISION_HPP

#include "geometrycentral/surface/manifold_surface_mesh.h"
#include "geometrycentral/surface/vertex_position_geometry.h"

namespace geometry
{

namespace subdivision
{

using MeshAndGeometry = std::tuple<std::unique_ptr<geometrycentral::surface::ManifoldSurfaceMesh>,
                                   std::unique_ptr<geometrycentral::surface::VertexPositionGeometry>>;

/*
Standard Catmull-Clark subdivision algorithm. Requires 2-manifold closed polygon mesh. The mesh
may contain n-gons (e.g., a dodecahedron) and holes (e.g., a torus).
See details on "Catmull, E., & Clark, J. (1978). Recursively generated B-spline surfaces on arbitrary topological
meshes. Computer-aided design, 10(6), 350-355."
*/
MeshAndGeometry standard_catmull_clark(std::unique_ptr<geometrycentral::surface::ManifoldSurfaceMesh> mesh,
                                       std::unique_ptr<geometrycentral::surface::VertexPositionGeometry> geometry);

} // namespace subdivision

} // namespace geometry

#endif // SUBDIVISION_HPP