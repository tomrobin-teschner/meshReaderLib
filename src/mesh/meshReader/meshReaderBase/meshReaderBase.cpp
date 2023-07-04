// (c) 2023 by Tom-Robin Teschner, www.cfd.university 

// project include headers
#include "src/mesh/meshReader/meshReaderBase/meshReaderBase.hpp"
#include "meshReaderBase.hpp"

namespace cfd {
namespace mesh {

/// \name Constructors and destructors
/// @{
MeshReaderBase::MeshReaderBase(std::filesystem::path filePath) : _filePath(filePath) { }
/// @}

/// \name API interface that exposes behaviour to the caller
/// @{
auto MeshReaderBase::readMesh() -> void {
  readCoordinates();
  readCells();
  readBoundaries();
}
/// @}

/// \name Getters and setters
/// @{
auto MeshReaderBase::getCoordinates() const -> const MeshReaderBase::CoordinateType& {
  return _coordinates;
}

auto MeshReaderBase::getInteriorCells() const -> const MeshReaderBase::InteriorCellType& {
  return _interiorCells;
}

auto MeshReaderBase::getInteriorShapes() const -> const InteriorShapeType &
{
  return _interiorShapes;
}
auto MeshReaderBase::getBoundaryCells() const -> const MeshReaderBase::BoundaryCellType& {
  return _boundaryCells;
}

auto MeshReaderBase::getBoundaryShapes() const -> const BoundaryShapeType& {
  return _boundaryShapes;
}

auto MeshReaderBase::getBoundaryConditions() const -> const BoundaryConditionType& {
  return _boundaryConditions; 
}
/// @}

/// \name Overloaded operators
/// @{

/// @}

/// \name Private or protected implementation details, not exposed to the caller
/// @{

/// @}

}// end namespace mesh
}// end namespace cfd