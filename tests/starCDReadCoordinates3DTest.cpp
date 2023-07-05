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

bool checkCoordinates3D(cfd::mesh::MeshReaderBase &meshReader) {
  auto coordinates = meshReader.getCoordinates();

  assert(coordinates.size() == 12);

  assert(coordinates[0][Coordinate::X] == 0.0);
  assert(coordinates[0][Coordinate::Y] == 0.0);
  assert(coordinates[0][Coordinate::Z] == 0.0);

  assert(coordinates[1][Coordinate::X] == 0.0);
  assert(coordinates[1][Coordinate::Y] == 0.0);
  assert(coordinates[1][Coordinate::Z] == 1.0);

  assert(coordinates[2][Coordinate::X] == 0.0);
  assert(coordinates[2][Coordinate::Y] == 1.0);
  assert(coordinates[2][Coordinate::Z] == 1.0);

  assert(coordinates[3][Coordinate::X] == 0.0);
  assert(coordinates[3][Coordinate::Y] == 1.0);
  assert(coordinates[3][Coordinate::Z] == 0.0);

  assert(coordinates[4][Coordinate::X] == -1.0);
  assert(coordinates[4][Coordinate::Y] == 0.5);
  assert(coordinates[4][Coordinate::Z] == 0.5);

  assert(coordinates[5][Coordinate::X] == -1.0);
  assert(coordinates[5][Coordinate::Y] == 1.0);
  assert(coordinates[5][Coordinate::Z] == 0.5);

  assert(coordinates[6][Coordinate::X] == 1.0);
  assert(coordinates[6][Coordinate::Y] == 1.0);
  assert(coordinates[6][Coordinate::Z] == 0.0);

  assert(coordinates[7][Coordinate::X] == 2.0);
  assert(coordinates[7][Coordinate::Y] == 0.5);
  assert(coordinates[7][Coordinate::Z] == 0.0);

  assert(coordinates[8][Coordinate::X] == 1.0);
  assert(coordinates[8][Coordinate::Y] == 0.0);
  assert(coordinates[8][Coordinate::Z] == 0.0);

  assert(coordinates[9][Coordinate::X] == 1.0);
  assert(coordinates[9][Coordinate::Y] == 0.0);
  assert(coordinates[9][Coordinate::Z] == 1.0);

  assert(coordinates[10][Coordinate::X] == 2.0);
  assert(coordinates[10][Coordinate::Y] == 0.5);
  assert(coordinates[10][Coordinate::Z] == 1.0);

  assert(coordinates[11][Coordinate::X] == 1.0);
  assert(coordinates[11][Coordinate::Y] == 1.0);
  assert(coordinates[11][Coordinate::Z] == 1.0);

  return true;
}

int main() {
  std::filesystem::path filePath3D = "mesh/mesh3D";
  cfd::mesh::StarCD mesh3D(filePath3D);
  mesh3D.readMesh();
  
  return !checkCoordinates3D(mesh3D);
}