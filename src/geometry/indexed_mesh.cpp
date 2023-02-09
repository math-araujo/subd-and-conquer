#include "indexed_mesh.hpp"
#include "geometrycentral/surface/surface_mesh_factories.h"
#include "geometrycentral/utilities/vector3.h"

namespace geometry
{

std::tuple<std::unique_ptr<geometrycentral::surface::ManifoldSurfaceMesh>,
           std::unique_ptr<geometrycentral::surface::VertexPositionGeometry>>
to_halfedge(const IndexedMesh& indexed_mesh)
{
    using namespace geometrycentral;
    using namespace geometrycentral::surface;

    // geometry-central only accepts it's own internal Vector3 type, hence the conversion
    std::vector<Vector3> gc_positions;
    gc_positions.reserve(indexed_mesh.positions.size());
    for (const auto& position : indexed_mesh.positions)
    {
        gc_positions.emplace_back(Vector3{position.x, position.y, position.z});
    }
    return makeManifoldSurfaceMeshAndGeometry(indexed_mesh.faces_indices, gc_positions);
}

} // namespace geometry