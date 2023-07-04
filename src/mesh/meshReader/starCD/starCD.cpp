// (c) 2023 by Tom-Robin Teschner, www.cfd.university 

// project include headers
#include "src/mesh/meshReader/starCD/starCD.hpp"


namespace cfd {
namespace mesh {

/// \name Constructors and destructors
/// @{
StarCD::StarCD(std::filesystem::path filePath) : MeshReaderBase(filePath) {
  getNumberOfDimensions();
  getNumberOfVertices();
  getNumberOfCells();
  getNumberOfBoundaries();

  _shape2indices = {
    {Shape::EDGE, {1, 2}},
    {Shape::TRIANGLE, {1, 2, 3}},
    {Shape::QUADRILATERAL, {1, 2, 3, 4}},
    {Shape::TETRAHEDRON, {1, 2, 3, 5}},
    {Shape::PYRAMID, {1, 2, 3, 4, 5}},
    {Shape::PRISM, {1, 2, 3, 5, 6, 7}},
    {Shape::HEXAHEDRON, {1, 2, 3, 4, 5, 6, 7, 8}}
  };
}
/// @}

/// \name API interface that exposes behaviour to the caller
/// @{
auto StarCD::readCoordinates() -> void {
  _coordinates.resize(_numberOfVertices);
  auto file = _filePath;
  file.replace_extension(".vrt");
  cfd::utilities::FileReader fileReader(file);
  std::string line;
  IndexType currentVertexIndex = 0;

  while (fileReader.getNextLine(line)) {
    auto args = cfd::utilities::StringHandler::split(line, " \t");
    auto coordinatesAsString = args[1];
    cfd::utilities::StringHandler::strip(coordinatesAsString);
    auto currentCoordinates = cfd::utilities::StringHandler::splitStringIntoEqualParts(coordinatesAsString, 3);
    
    auto x = cfd::utilities::StringHandler::convertStringToNumber<FloatType>(currentCoordinates[0]);
    auto y = cfd::utilities::StringHandler::convertStringToNumber<FloatType>(currentCoordinates[1]);
    auto z = cfd::utilities::StringHandler::convertStringToNumber<FloatType>(currentCoordinates[2]);

    _coordinates[currentVertexIndex][Coordinate::X] = x;
    _coordinates[currentVertexIndex][Coordinate::Y] = y;
    _coordinates[currentVertexIndex][Coordinate::Z] = z;
    ++currentVertexIndex;
  }
}
auto StarCD::readCells() -> void {
  _interiorCells.resize(_numberOfCells);
  auto file = _filePath;
  file.replace_extension(".cel");
  cfd::utilities::FileReader fileReader(file);
  std::string line;
  IndexType currentCellIndex = 0;

  while (fileReader.getNextLine(line)) {
    auto args = cfd::utilities::StringHandler::split(line, " \t");
    for (auto &arg : args)
      cfd::utilities::StringHandler::strip(arg);

    CellType cell;
    getInteriorShape(args, [&args, &cell, this](Shape shape) {
      _interiorShapes.push_back(shape);
      for (auto index : _shape2indices[shape])
        cell.push_back(cfd::utilities::StringHandler::convertStringToNumber<IndexType>(args[index]) - 1);
    });

    _interiorCells[currentCellIndex] = (cell);
    ++currentCellIndex;
  }
}
auto StarCD::readBoundaries() -> void {
  _boundaryCells.resize(_numberOfBoundaries);
  _boundaryShapes.resize(_numberOfBoundaries);
  _boundaryConditions.resize(_numberOfBoundaries);
  auto file = _filePath;
  file.replace_extension(".bnd");
  cfd::utilities::FileReader fileReader(file);
  std::string line;

  while (fileReader.getNextLine(line)) {
    auto args = cfd::utilities::StringHandler::split(line, " \t");
    for (auto &arg : args)
      cfd::utilities::StringHandler::strip(arg);
    auto bcIndex = cfd::utilities::StringHandler::convertStringToNumber<IndexType>(args[5]) - 1;

    CellType bcCell;
    getBoundaryShape(args, [&args, &bcIndex, &bcCell, this](Shape shape) {
      _boundaryShapes[bcIndex].push_back(shape);
      for (auto index : _shape2indices[shape])
        bcCell.push_back(cfd::utilities::StringHandler::convertStringToNumber<IndexType>(args[index]) - 1);
    });

    _boundaryCells[bcIndex].push_back(bcCell);

    getBoundaryCondition(args, [&bcIndex, this](BoundaryCondition bc) {
      _boundaryConditions[bcIndex] = bc;
    });
  }
}
/// @}

/// \name Getters and setters
/// @{

/// @}

/// \name Overloaded operators
/// @{

/// @}

/// \name Private or protected implementation details, not exposed to the caller
/// @{
auto StarCD::getNumberOfDimensions() -> void {
  auto file = _filePath;
  file.replace_extension(".cel");
  cfd::utilities::FileReader fileReader(file);
  std::string line;
  fileReader.getNextLine(line);
  auto individualComponents = cfd::utilities::StringHandler::split(line, " \t");
  
  if (individualComponents.size() == 7)
    _numberOfDimensions = Dimension::Two;
  else if (individualComponents.size() == 11)
    _numberOfDimensions = Dimension::Three;
  else
    std::runtime_error("Could not detect number of dimensions correctly!");
}

auto StarCD::getNumberOfVertices() -> void {
  auto file = _filePath;
  file.replace_extension(".vrt");

  cfd::utilities::FileReader fileReader(file);
  std::string line;
  while (fileReader.getNextLine(line))
    _numberOfVertices++;
}

auto StarCD::getNumberOfCells() -> void {
  auto file = _filePath;
  file.replace_extension(".cel");
  cfd::utilities::FileReader fileReader(file);
  std::string line;
  while (fileReader.getNextLine(line))
    _numberOfCells++;
}

auto StarCD::getNumberOfBoundaries() -> void {
  auto file = _filePath;
  file.replace_extension(".bnd");
  cfd::utilities::FileReader fileReader(file);
  std::string line, lastLine;
  
  while (fileReader.getNextLine(line)) {
    lastLine = line;
  }
  
  auto args = cfd::utilities::StringHandler::split(lastLine, " \t");
  auto numberOfBoundariesAsString = args[5];
  cfd::utilities::StringHandler::strip(numberOfBoundariesAsString);
  _numberOfBoundaries = cfd::utilities::StringHandler::convertStringToNumber<IndexType>(numberOfBoundariesAsString);
}
/// @}

}// end namespace mesh
}// end namespace cfd