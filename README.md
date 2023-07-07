# Introduction

This repository showcases how to implement mesh reading for Computational Fluid Dynamics (CFD) applications using C++. It currently supports the following file formats:

## Unstructured:
- StarCD

Additional formats to be implemented

# Compiling

To compile and use the mesh reading library, use CMake with the usual commands, i.e.

```bash
cd /change/to/project/root/dir
mkdir build/
cd build
cmake -DCMAKE_BUILD_TYPE:STRING=Release -DCMAKE_INSTALL_PREFIX:PATH=/usr/local ..
cmake --build . --config Release --target all -j 4
```

To install the library into the path specified by ```-DCMAKE_INSTALL_PREFIX```, use the following command

```bash
cmake --build . --target install
```

# Example

A minimal code example may look like this

```c++
#include <iostream>
#include "meshReader/meshReader.hpp"

int main() {
  // path to mesh file, including mesh name but no extension. Assuming the follwoing files exist
  // - mesh/file.vrt
  // - mesh/file.cel
  // - mesh/file.bnd
  // you would use the following code:
  std::filesystem::path filePath = "mesh/file";
  cfd::mesh::StarCD mesh(filePath);
  mesh.readMesh();
  
  // cells coordinates
  auto coordinates = mesh2D.getCoordinates();

  std::cout << "Reading coordinates" << std::endl;
  for (const auto &coordinate : coordinates) {
    std::cout << coordinate[Coordinate::X] << " ";
    std::cout << coordinate[Coordinate::Y] << " ";
    std::cout << coordinate[Coordinate::Z] << std::endl;
  }
  
  // interior cells
  auto interiorCells = mesh2D.getInteriorCells();
  auto interiorShapes = mesh2D.getInteriorShapes();
  
  std::cout << "\nReading cells" << std::endl;
  for (int cellIndex = 0; cellIndex < interiorCells.size(); ++cellIndex) {
    if (interiorShapes[cellIndex] == Shape::TRIANGLE) {
      std::cout << interiorCells[cellIndex][0] << " ";
      std::cout << interiorCells[cellIndex][1] << " ";
      std::cout << interiorCells[cellIndex][2] << std::endl;
    } else if (interiorShapes[cellIndex] == Shape::QUADRILATERAL) {
      std::cout << interiorCells[cellIndex][0] << " ";
      std::cout << interiorCells[cellIndex][1] << " ";
      std::cout << interiorCells[cellIndex][2] << " ";
      std::cout << interiorCells[cellIndex][3] << std::endl;
    }
  }
  
  // boundaries
  auto boundaryCells = mesh2D.getBoundaryCells();
  auto boundaryShapes = mesh2D.getBoundaryShapes();
  auto boundaryConditions = mesh2D.getBoundaryConditions();
  auto numberOfBoundaries = boundaryCells.size();

  std::cout << "\nReading boundaries" << std::endl;
  for (int boundaryIndex = 0; boundaryIndex < numberOfBoundaries; ++boundaryIndex) {
    if (boundaryShapes[boundaryIndex][0] == Shape::EDGE) { // first cell (index 0)
      std::cout << boundaryCells[boundaryIndex][0][0] << " ";
      std::cout << boundaryCells[boundaryIndex][0][1] << std::endl;
    } else if (boundaryShapes[boundaryIndex][0] == Shape::QUADRILATERAL) {
      std::cout << boundaryCells[boundaryIndex][0][0] << " ";
      std::cout << boundaryCells[boundaryIndex][0][1] << " ";
      std::cout << boundaryCells[boundaryIndex][0][2] << " ";
      std::cout << boundaryCells[boundaryIndex][0][3] << std::endl;
    }
    if (boundaryConditions[boundaryIndex] == BoundaryCondition::Inlet)
      std::cout << "Inlet boundary condition assigned" << std::endl;
    else if (boundaryConditions[boundaryIndex] == BoundaryCondition::Outlet)
      std::cout << "Outlet boundary condition assigned" << std::endl;
  }

  return 0;
}
```

# Testing

You can test that the library is compiled correctly and working by executing the tests with ctest

```bash
cd /change/to/project/root/dir/build/tests
ctest
```

# Documentation

To build the associated documentation with doxygen, first ensure that doxygen and graphviz are installed. Use you favourite package manager to install them, on Ubuntu this would result in

```bash
sudo apt install -y doxygen graphviz
```

CMake can build the documentation for us automatically, though by default it is not built. To activate the documentation, you have to configure cmake with the ```BUILD_DOC``` option set to ON, i.e.

```bash
cmake -DCMAKE_BUILD_TYPE:STRING=Release -DCMAKE_INSTALL_PREFIX:PATH=/usr/local -DBUILD_DOC:BOOL=ON ..
```

Then, when you build all targets, the documentation will be created within the build folder, specifically in the ```build/docs/html``` folder. Open the ```index.html``` file to see the code documentation.

# License

This library is distributed under the permissive MIT License, see the ```LICENSE``` file for additional information.