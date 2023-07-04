// (c) 2023 by Tom-Robin Teschner, www.cfd.university 

namespace cfd {
namespace utilities {

/// \name Constructors and destructors
/// @{

/// @}

/// \name API interface that exposes behaviour to the caller
/// @{
template<typename Type>
auto StringHandler::convertStringToNumber(const std::string &line) -> Type {
  // convert string to temporary number (double)
  auto tempNumber = std::stod(line);

  // since we have a number now, we can call static_cast and convert easily
  return static_cast<Type>(tempNumber);
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

/// @}

}// end namespace utilities
}// end namespace cfd