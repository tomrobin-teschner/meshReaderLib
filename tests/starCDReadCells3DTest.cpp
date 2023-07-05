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

bool checkCells3D(cfd::mesh::MeshReaderBase &meshReader) {
  std::cout << "> checking 3D cell reading" << std::endl;
  auto cells = meshReader.getInteriorCells();
  auto shapes = meshReader.getInteriorShapes();

  assert(cells.size() == 4);

  assert(cells[0][0] == 3);
  assert(cells[0][1] == 0);
  assert(cells[0][2] == 1);
  assert(cells[0][3] == 2);
  assert(cells[0][4] == 4);

  assert(cells[1][0] == 3);
  assert(cells[1][1] == 4);
  assert(cells[1][2] == 2);
  assert(cells[1][3] == 5);

  assert(cells[2][0] == 8);
  assert(cells[2][1] == 7);
  assert(cells[2][2] == 6);
  assert(cells[2][3] == 9);
  assert(cells[2][4] == 10);
  assert(cells[2][5] == 11);

  assert(cells[3][0] == 3);
  assert(cells[3][1] == 0);
  assert(cells[3][2] == 8);
  assert(cells[3][3] == 6);
  assert(cells[3][4] == 2);
  assert(cells[3][5] == 1);
  assert(cells[3][6] == 9);
  assert(cells[3][7] == 11);

  assert(shapes.size() == 4);

  assert(shapes[0] == Shape::PYRAMID);
  assert(shapes[1] == Shape::TETRAHEDRON);
  assert(shapes[2] == Shape::PRISM);
  assert(shapes[3] == Shape::HEXAHEDRON);

  return true;
}

int main() {
  std::filesystem::path filePath3D = "mesh/mesh3D";
  cfd::mesh::StarCD mesh3D(filePath3D);
  mesh3D.readMesh();

  return !checkCells3D(mesh3D);
}