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

bool checkCoordinates2D(cfd::mesh::MeshReaderBase &meshReader) {
  std::cout << "> checking 2D coordinate reading" << std::endl;
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

  return true;
}

bool checkCoordinates3D(cfd::mesh::MeshReaderBase &meshReader) {
  std::cout << "> checking 3D coordinate reading" << std::endl;
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

bool checkCells2D(cfd::mesh::MeshReaderBase &meshReader) {
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

  return true;
}

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

bool checkBoundaries2D(cfd::mesh::MeshReaderBase &meshReader) {
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

  return true;
}

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
  std::filesystem::path filePath2D = "mesh/mesh2D";
  std::filesystem::path filePath3D = "mesh/mesh3D";
  
  cfd::mesh::StarCD mesh2D(filePath2D);
  cfd::mesh::StarCD mesh3D(filePath3D);
  
  mesh2D.readMesh();
  mesh3D.readMesh();

  // coordinates / vertices
  if (!checkCoordinates2D(mesh2D))
    std::cerr << "2D coordinate reading failed" << std::endl;
  if (!checkCoordinates3D(mesh3D))
    std::cerr << "3D coordinate reading failed" << std::endl;
  
  // cells
  if (!checkCells2D(mesh2D))
    std::cerr << "2D cell reading failed" << std::endl;
  if (!checkCells3D(mesh3D))
    std::cerr << "3D cell reading failed" << std::endl;

  // boundaries
  if (!checkBoundaries2D(mesh2D))
    std::cerr << "2D boundary reading failed" << std::endl;
  if (!checkBoundaries3D(mesh3D))
    std::cerr << "3D boundary reading failed" << std::endl;

  return 0;
}