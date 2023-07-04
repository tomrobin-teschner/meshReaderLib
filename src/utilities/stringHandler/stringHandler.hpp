// (c) 2023 by Tom-Robin Teschner, www.cfd.university 

#ifndef STRINGHANDLER_HPP
#define STRINGHANDLER_HPP

// c++ include headers
#include <string>
#include <vector>
#include <optional>
#include <stdexcept>
#include <algorithm>

// third-party include headers

// project include headers

namespace cfd {
namespace utilities {

/**
* \class StringHandler
* \brief Exposes functionality for common string processing tasks
* \ingroup utilities
*
* The purpose of this class is to provide functionality that is commonly
* applied to a string. In particular, we need to be able to split strings into
* separate parts based on a delimiter character or into equally sized parts, 
* remove leading and trailing whitespaces, and convert strings into numbers.
*
* Example usage:
* \code
* std::string line = "1, 2, 3, 4, 5, 6, 7, 8, 9, 10";
* auto stringList = cfd::utilities::StringHandler::split(line, ",");
* for (auto &argument : stringList) {
*   cfd::utilities::StringHandler::strip(argument);
*   auto number = cfd::utilities::StringHandler::convertStringToNumber<int>(argument);
*   std::cout << number << std::endl;
* }
* \endcode
*/

class StringHandler {
/// \name Custom types used in this class
/// @{
public:
  using StringList = typename std::vector<std::string>;
/// @}

/// \name Constructors and destructors
/// @{
public:
  StringHandler() = delete;
  ~StringHandler() = delete;
/// @}

/// \name API interface that exposes behaviour to the caller
/// @{
public:
  auto static split(std::string &line, const std::optional<std::string> &delimiter = std::nullopt) -> StringList;
  auto static strip(std::string &line) -> void;
  auto static splitStringIntoEqualParts(std::string &line, const int numParts) -> StringList;
  
  template<typename Type>
  auto static convertStringToNumber(const std::string &line) -> Type;
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
protected:

/// @}

/// \name Encapsulated data (private or protected variables)
/// @{
protected:

/// @}
};

}// end namespace utilities
}// end namespace cfd

#include "src/utilities/stringHandler/stringHandler.tpp"

#endif
