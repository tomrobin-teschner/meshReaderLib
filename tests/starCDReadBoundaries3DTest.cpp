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

bool checkBoundaries3D(cfd::mesh::MeshReaderBase &meshReader) {
  std::cout << "> checking 3D boundary reading" << std::endl;
  auto cells = meshReader.getBoundaryCells();
  auto shapes = meshReader.getBoundaryShapes();
  auto bc = meshReader.getBoundaryConditions();

  assert(cells.size() == 6);
  assert(cells[0].size() == 2);
  assert(cells[1].size() == 1);
  assert(cells[2].size() == 2);
  assert(cells[3].size() == 2);
  assert(cells[4].size() == 1);
  assert(cells[5].size() == 6);

  assert(cells[0][0][0] == 7);
  assert(cells[0][0][1] == 6);
  assert(cells[0][0][2] == 8);

  assert(cells[0][1][0] == 8);
  assert(cells[0][1][1] == 6);
  assert(cells[0][1][2] == 3);
  assert(cells[0][1][3] == 0);

  assert(shapes.size() == 6);
  assert(shapes[0].size() == 2);
  assert(shapes[1].size() == 1);
  assert(shapes[2].size() == 2);
  assert(shapes[3].size() == 2);
  assert(shapes[4].size() == 1);
  assert(shapes[5].size() == 6);

  assert(shapes[0][0] == Shape::TRIANGLE);
  assert(shapes[0][1] == Shape::QUADRILATERAL);
  
  assert(shapes[1][0] == Shape::QUADRILATERAL);
  
  assert(shapes[2][0] == Shape::TRIANGLE);
  assert(shapes[2][1] == Shape::QUADRILATERAL);

  assert(shapes[3][0] == Shape::QUADRILATERAL);
  assert(shapes[3][1] == Shape::QUADRILATERAL);

  assert(shapes[4][0] == Shape::QUADRILATERAL);

  assert(shapes[5][0] == Shape::TRIANGLE);
  assert(shapes[5][1] == Shape::TRIANGLE);
  assert(shapes[5][2] == Shape::TRIANGLE);
  assert(shapes[5][3] == Shape::TRIANGLE);
  assert(shapes[5][4] == Shape::TRIANGLE);
  assert(shapes[5][5] == Shape::TRIANGLE);

  assert(bc.size() == 6);
  assert(bc[0] == BoundaryCondition::Periodic);
  assert(bc[1] == BoundaryCondition::Outlet);
  assert(bc[2] == BoundaryCondition::Periodic);
  assert(bc[3] == BoundaryCondition::Symmetry);
  assert(bc[4] == BoundaryCondition::Wall);
  assert(bc[5] == BoundaryCondition::Inlet);

  return true;
}

int main() {
  std::filesystem::path filePath3D = "mesh/mesh3D";
  cfd::mesh::StarCD mesh3D(filePath3D);
  mesh3D.readMesh();

  return !checkBoundaries3D(mesh3D);
}