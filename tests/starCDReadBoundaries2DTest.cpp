// c++ include headers
#include <iostream>
#include <string>
#include <filesystem>
#include <cassert>

// third-party include headers

// project include headers
#include "src/mesh/meshReader/meshReaderBase/meshReaderBase.hpp"
#include "src/mesh/meshReader/starCD/starCD.hpp"
#include "src/utilities/types/enums.hpp"

int checkBoundaries2D(cfd::mesh::MeshReaderBase &meshReader) {
  std::cout << "> checking 2D boundary reading" << std::endl;
  auto cells = meshReader.getBoundaryCells();
  auto shapes = meshReader.getBoundaryShapes();
  auto bc = meshReader.getBoundaryConditions();

  assert(cells.size() == 5);
  assert(cells[0].size() == 1);
  assert(cells[1].size() == 1);
  assert(cells[2].size() == 1);
  assert(cells[3].size() == 1);
  assert(cells[4].size() == 1);

  assert(cells[0][0][0] == 1);
  assert(cells[0][0][1] == 2);

  assert(cells[1][0][0] == 2);
  assert(cells[1][0][1] == 3);

  assert(cells[2][0][0] == 3);
  assert(cells[2][0][1] == 4);

  assert(cells[3][0][0] == 0);
  assert(cells[3][0][1] == 1);

  assert(cells[4][0][0] == 4);
  assert(cells[4][0][1] == 0);

  assert(shapes.size() == 5);
  assert(shapes[0].size() == 1);
  assert(shapes[1].size() == 1);
  assert(shapes[2].size() == 1);
  assert(shapes[3].size() == 1);
  assert(shapes[4].size() == 1);

  assert(shapes[0][0] == Shape::EDGE);
  assert(shapes[1][0] == Shape::EDGE);
  assert(shapes[2][0] == Shape::EDGE);
  assert(shapes[3][0] == Shape::EDGE);
  assert(shapes[4][0] == Shape::EDGE);

  assert(bc.size() == 5);
  assert(bc[0] == BoundaryCondition::Periodic);
  assert(bc[1] == BoundaryCondition::Outlet);
  assert(bc[2] == BoundaryCondition::Symmetry);
  assert(bc[3] == BoundaryCondition::Wall);
  assert(bc[4] == BoundaryCondition::Inlet);

  return 0;
}

int main() {
  std::filesystem::path filePath2D = "mesh/mesh2D";
  cfd::mesh::StarCD mesh2D(filePath2D);
  mesh2D.readMesh();
  
  return checkBoundaries2D(mesh2D);
}