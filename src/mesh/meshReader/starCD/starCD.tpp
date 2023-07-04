// (c) 2023 by Tom-Robin Teschner, www.cfd.university 

namespace cfd {
namespace mesh {

/// \name Constructors and destructors
/// @{

/// @}

/// \name API interface that exposes behaviour to the caller
/// @{

/// @}

/// \name Getters and setters
/// @{

/// @}

/// \name Overloaded operators
/// @{

/// @}

/// \name Private or protected implementation details, not exposed to the caller
/// @{
template<typename FunctionType>
void StarCD::getInteriorShape(const cfd::utilities::StringHandler::StringList &args, FunctionType function) {
  if (_numberOfDimensions == Dimension::Two) {
    if (args[3] == std::string("0") && args[4] == std::string("0")) {
      function(Shape::EDGE);
    } else if (args[3] == args[4]) {
      function(Shape::TRIANGLE);
    } else if (args[3] != args[4]) {
      function(Shape::QUADRILATERAL);
    }
  } else if (_numberOfDimensions == Dimension::Three) {
    if (args[3] != args[4] && args[5] == args[6] && args[5] == args[7] && args[5] == args[8]) {
      function(Shape::PYRAMID);
    } else if (args[3] == args[4] && args[5] == args[6] &&  args[5] == args[7] && args[5] == args[8]) {
      function(Shape::TETRAHEDRON);
    } else if (args[3] == args[4] && args[5] != args[6] && args[7] == args[8]) {
      function(Shape::PRISM);
    } else {
      function(Shape::HEXAHEDRON);
    }
  }
}

template<typename FunctionType>
void StarCD::getBoundaryShape(const cfd::utilities::StringHandler::StringList &args, FunctionType function) {
  if (_numberOfDimensions == Dimension::Two) {
    // can only ever be an edge in 2D
    function(Shape::EDGE);
  } else if (_numberOfDimensions == Dimension::Three) {
    if (args[3] == args[4]) {
      function(Shape::TRIANGLE);
    } else if (args[3] != args[4]) {
      function(Shape::QUADRILATERAL);
    }
  }
}

template<typename FunctionType>
void StarCD::getBoundaryCondition(const cfd::utilities::StringHandler::StringList &args, FunctionType function) {
  if (args[7] == std::string("INLE")) {
    function(BoundaryCondition::Inlet);
  } else if (args[7] == std::string("OUTL")) {
    function(BoundaryCondition::Outlet);
  } else if (args[7] == std::string("WALL")) {
    function(BoundaryCondition::Wall);
  } else if (args[7] == std::string("SYMP")) {
    function(BoundaryCondition::Symmetry);
  } else if (args[7] == std::string("CYCL")) {
    function(BoundaryCondition::Periodic);
  }
}
/// @}

}// end namespace mesh
}// end namespace cfd