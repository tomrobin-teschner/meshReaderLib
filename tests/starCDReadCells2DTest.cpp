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

int checkCells2D(cfd::mesh::MeshReaderBase &meshReader) {
  std::cout << "> checking 2D cell reading" << std::endl;
  auto cells = meshReader.getInteriorCells();
  auto shapes = meshReader.getInteriorShapes();

  assert(cells.size() == 2);

  assert(cells[0][0] == 1);
  assert(cells[0][1] == 2);
  assert(cells[0][2] == 3);

  assert(cells[1][0] == 4);
  assert(cells[1][1] == 0);
  assert(cells[1][2] == 1);
  assert(cells[1][3] == 3);

  assert(shapes.size() == 2);

  assert(shapes[0] == Shape::TRIANGLE);
  assert(shapes[1] == Shape::QUADRILATERAL);

  return 0;
}

int main() {
  std::filesystem::path filePath2D = "mesh/mesh2D";
  cfd::mesh::StarCD mesh2D(filePath2D);
  mesh2D.readMesh();

  return checkCells2D(mesh2D);
}