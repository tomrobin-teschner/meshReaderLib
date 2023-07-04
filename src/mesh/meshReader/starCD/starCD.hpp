// (c) 2023 by Tom-Robin Teschner, www.cfd.university 

#ifndef STARCD_HPP
#define STARCD_HPP

// c++ include headers
#include <filesystem>
#include <map>
#include <vector>
#include <string>

// third-party include headers

// project include headers
#include "src/mesh/meshReader/meshReaderBase/meshReaderBase.hpp"
#include "src/utilities/types/types.hpp"
#include "src/utilities/types/enums.hpp"
#include "src/utilities/fileReader/fileReader.hpp"
#include "src/utilities/stringHandler/stringHandler.hpp"

namespace cfd {
namespace mesh {

/**
* \class StarCD
* \brief A class reading mesh files using the STAR-CD format
* \ingroup mesh
*
* The purpose of this class is to provide mesh reading capabilities for the
* unstructured STAR-CD mesh format. It reads 3 files
* - *.vrt: This file contains coordinates of vertices
* - *.cel: This file contains information on which vertices form a cell
* - *.bnd: This file contains the different boundary conditions
*
* Example usage:
* \code
* // path to mesh file, including mesh name but no extension. Assuming the follwoing files exist
* // - mesh/file.vrt
* // - mesh/file.cel
* // - mesh/file.bnd
* // you would use the following code:
* std::filesystem::path filePath = "mesh/file";
* cfd::mesh::StarCD mesh(filePath);
* mesh.readMesh();
* 
* // cells coordinates
* std::cout << "Reading coordinates" << std::endl;
* auto coordinates = mesh2D.getCoordinates();
* for (const auto &coordinate : coordinates) {
*   std::cout << coordinate[Coordinate::X] << " ";
*   std::cout << coordinate[Coordinate::Y] << " ";
*   std::cout << coordinate[Coordinate::Z] << std::endl;
* }
* 
* // interior cells
* std::cout << "\nReading cells" << std::endl;
* auto interiorCells = mesh2D.getInteriorCells();
* auto interiorShapes = mesh2D.getInteriorShapes();
* for (int cellIndex = 0; cellIndex < interiorCells.size(); ++cellIndex) {
*   if (interiorShapes[cellIndex] == Shape::TRIANGLE) {
*     std::cout << interiorCells[cellIndex][0] << " ";
*     std::cout << interiorCells[cellIndex][1] << " ";
*     std::cout << interiorCells[cellIndex][2] << std::endl;
*   } else if (interiorShapes[cellIndex] == Shape::QUADRILATERAL) {
*     std::cout << interiorCells[cellIndex][0] << " ";
*     std::cout << interiorCells[cellIndex][1] << " ";
*     std::cout << interiorCells[cellIndex][2] << " ";
*     std::cout << interiorCells[cellIndex][3] << std::endl;
*   }
* }
** // boundaries
* auto boundaryCells = mesh2D.getBoundaryCells();
* auto boundaryShapes = mesh2D.getBoundaryShapes();
* auto boundaryConditions = mesh2D.getBoundaryConditions();
* auto numberOfBoundaries = boundaryCells.size();
* std::cout << "\nReading boundaries" << std::endl;
* for (int boundaryIndex = 0; boundaryIndex < numberOfBoundaries; ++boundaryIndex) {
*   if (boundaryShapes[boundaryIndex][0] == Shape::EDGE) { // first cell (index 0)
*     std::cout << boundaryCells[boundaryIndex][0][0] << " ";
*     std::cout << boundaryCells[boundaryIndex][0][1] << std::endl;
*   } else if (boundaryShapes[boundaryIndex][0] == Shape::QUADRILATERAL) {
*     std::cout << boundaryCells[boundaryIndex][0][0] << " ";
*     std::cout << boundaryCells[boundaryIndex][0][1] << " ";
*     std::cout << boundaryCells[boundaryIndex][0][2] << " ";
*     std::cout << boundaryCells[boundaryIndex][0][3] << std::endl;
*   }
*   if (boundaryConditions[boundaryIndex] == BoundaryCondition::Inlet)
*     std::cout << "Inlet boundary condition assigned" << std::endl;
*   else if (boundaryConditions[boundaryIndex] == BoundaryCondition::Outlet)
*     std::cout << "Outlet boundary condition assigned" << std::endl;
* }
* \endcode
*/

class StarCD : public MeshReaderBase {
/// \name Custom types used in this class
/// @{
public:
  using CoordinateType = typename MeshReaderBase::CoordinateType;
  using CellsType = typename MeshReaderBase::InteriorCellType;
  using InteriorShapeType = typename MeshReaderBase::InteriorShapeType;
  using BoundaryCellType = typename MeshReaderBase::BoundaryCellType;

/// @}

/// \name Constructors and destructors
/// @{
public:
  StarCD(std::filesystem::path filePath);
  ~StarCD() = default;
/// @}

/// \name API interface that exposes behaviour to the caller
/// @{
public:

/// @}

/// \name Getters and setters
/// @{
public:
  
/// @}

/// \name Overloaded operators
/// @{
public:

/// @}

/// \name Private or protected implementation details, not exposed to the caller
/// @{
private:
  virtual void getNumberOfDimensions() override final;
  virtual void getNumberOfVertices() override final;
  virtual void getNumberOfCells() override final;
  virtual void getNumberOfBoundaries() override final;

  virtual void readCoordinates() override final;
  virtual void readCells() override final;
  virtual void readBoundaries() override final;

  template<typename FunctionType>
  void getInteriorShape(const cfd::utilities::StringHandler::StringList &args, FunctionType function);

  template<typename FunctionType>
  void getBoundaryShape(const cfd::utilities::StringHandler::StringList &args, FunctionType function);

  template<typename FunctionType>
  void getBoundaryCondition(const cfd::utilities::StringHandler::StringList &args, FunctionType function);
/// @}

/// \name Encapsulated data (private or protected variables)
/// @{
private:
  std::map<Shape, std::vector<IndexType>> _shape2indices = {};
/// @}
};

}// end namespace mesh
}// end namespace cfd

#include "src/mesh/meshReader/starCD/starCD.tpp"

#endif
