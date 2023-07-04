// (c) 2023 by Tom-Robin Teschner, www.cfd.university 

#ifndef COMPUTATIONALMESH_HPP
#define COMPUTATIONALMESH_HPP

// c++ include headers
#include <filesystem>
#include <vector>
#include <array>
#include <map>

// third-party include headers

// project include headers
#include "src/utilities/types/types.hpp"
#include "src/utilities/types/enums.hpp"

namespace cfd {
namespace mesh {

/**
* \class MeshReaderBase
* \brief Base class for mesh reading
* \ingroup mesh
*
* The purpose of this class is to provide the required function definitions
* needed to be implemented by derived classes. It exposes custom types and
* variables that derived class can use and populate.
*
* For example usages of this class, see derived implemented classes for specific syntax.
*/

class MeshReaderBase {
/// \name Custom types used in this class
/// @{
public:
  using VertexType = typename std::array<FloatType, 3>;
  using CoordinateType = typename std::vector<VertexType>;
  
  using CellType = typename std::vector<IndexType>;

  using InteriorCellType = typename std::vector<CellType>;
  using InteriorShapeType = typename std::vector<Shape>;

  using BoundaryCellType = typename std::vector<std::vector<CellType>>;
  using BoundaryShapeType = typename std::vector<std::vector<Shape>>;
  using BoundaryConditionType = typename std::vector<BoundaryCondition>;
/// @}

/// \name Constructors and destructors
/// @{
public:
  MeshReaderBase(std::filesystem::path filePath);
  ~MeshReaderBase() = default;
/// @}

/// \name API interface that exposes behaviour to the caller
/// @{
public:
  auto readMesh() -> void;
/// @}

/// \name Getters and setters
/// @{
public:
  auto getCoordinates() const -> const CoordinateType&;
  auto getInteriorCells() const -> const InteriorCellType&;
  auto getInteriorShapes() const -> const InteriorShapeType&;
  auto getBoundaryCells() const -> const BoundaryCellType&;
  auto getBoundaryShapes() const -> const BoundaryShapeType&;
  auto getBoundaryConditions() const -> const BoundaryConditionType&;
/// @}

/// \name Overloaded operators
/// @{
public:

/// @}

/// \name Private or protected implementation details, not exposed to the caller
/// @{
protected:
  virtual void getNumberOfDimensions() = 0;

  virtual void getNumberOfVertices() = 0;
  virtual void getNumberOfCells() = 0;
  virtual void getNumberOfBoundaries() = 0;

  virtual void readCoordinates() = 0;
  virtual void readCells() = 0;
  virtual void readBoundaries() = 0;
/// @}

/// \name Encapsulated data (private or protected variables)
/// @{
protected:
  std::filesystem::path _filePath;
  IndexType _numberOfDimensions = 0; 
  IndexType _numberOfVertices = 0;
  IndexType _numberOfCells = 0;
  IndexType _numberOfBoundaries = 0;
  std::vector<IndexType> _numberOfCellsPerBoundary;

  CoordinateType _coordinates;
  InteriorCellType _interiorCells;
  InteriorShapeType _interiorShapes;
  BoundaryCellType _boundaryCells;
  BoundaryShapeType _boundaryShapes;
  BoundaryConditionType _boundaryConditions;
/// @}
};

}// end namespace mesh
}// end namespace cfd

#include "src/mesh/meshReader/meshReaderBase/meshReaderBase.tpp"

#endif
