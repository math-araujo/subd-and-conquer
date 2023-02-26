#ifndef SUBDIVISION_HPP
#define SUBDIVISION_HPP

#include "halfedge.hpp"

namespace geometry
{

namespace subdivision
{

/*
Standard Catmull-Clark subdivision algorithm. Requires 2-manifold closed polygon mesh. The mesh
may contain n-gons (e.g., a dodecahedron) and holes (e.g., a torus).
See details on "Catmull, E., & Clark, J. (1978). Recursively generated B-spline surfaces on arbitrary topological
meshes. Computer-aided design, 10(6), 350-355."
*/
Halfedge standard_catmull_clark(const Halfedge& halfedge);

/*
Catmull-Clark subdivision algorithm adapted for meshes with boundaries.
See details on "DeRose, T., Kass, M., & Truong, T. (1998, July). Subdivision surfaces in character animation. In
Proceedings of the 25th annual conference on Computer graphics and interactive techniques (pp. 85-94)."
*/
Halfedge derose_catmull_clark(const Halfedge& halfedge);

} // namespace subdivision

} // namespace geometry

#endif // SUBDIVISION_HPP