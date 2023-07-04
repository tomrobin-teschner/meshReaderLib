#ifndef ENUMS_HPP
#define ENUMS_HPP

enum Coordinate {
  X = 0,
  Y,
  Z
};

enum Dimension {
  One = 1,
  Two,
  Three
};

enum Shape {
  EDGE = 0,
  TRIANGLE,
  QUADRILATERAL,
  POLYGONE,
  TETRAHEDRON,
  PYRAMID,
  PRISM,
  HEXAHEDRON,
  POLYHEDRON
};

enum BoundaryCondition {
  Inlet = 0,
  Outlet,
  Symmetry,
  Wall,
  Periodic
};

#endif
