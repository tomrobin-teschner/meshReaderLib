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

int checkCoordinates2D(cfd::mesh::MeshReaderBase &meshReader) {
  auto coordinates = meshReader.getCoordinates();

  assert(coordinates.size() == 5);

  assert(coordinates[0][Coordinate::X] == 0.0);
  assert(coordinates[0][Coordinate::Y] == 0.0);
  assert(coordinates[0][Coordinate::Z] == 0.0);

  assert(coordinates[1][Coordinate::X] == 1.0);
  assert(coordinates[1][Coordinate::Y] == 0.0);
  assert(coordinates[1][Coordinate::Z] == 0.0);

  assert(coordinates[2][Coordinate::X] == 2.0);
  assert(coordinates[2][Coordinate::Y] == 0.5);
  assert(coordinates[2][Coordinate::Z] == 0.0);

  assert(coordinates[3][Coordinate::X] == 1.0);
  assert(coordinates[3][Coordinate::Y] == 1.0);
  assert(coordinates[3][Coordinate::Z] == 0.0);

  assert(coordinates[4][Coordinate::X] == 0.0);
  assert(coordinates[4][Coordinate::Y] == 1.0);
  assert(coordinates[4][Coordinate::Z] == 0.0);

  return 0;
}

int main() {
  std::filesystem::path filePath2D = "mesh/mesh2D";
  cfd::mesh::StarCD mesh2D(filePath2D);
  mesh2D.readMesh();

  return checkCoordinates2D(mesh2D);
}