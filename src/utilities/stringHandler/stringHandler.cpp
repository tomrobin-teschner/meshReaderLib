// (c) 2023 by Tom-Robin Teschner, www.cfd.university 

// project include headers
#include "src/utilities/stringHandler/stringHandler.hpp"

namespace cfd {
namespace utilities {

/// \name Constructors and destructors
/// @{

/// @}

/// \name API interface that exposes behaviour to the caller
/// @{
auto StringHandler::split(std::string &line, const std::optional<std::string> &delimiter) -> StringHandler::StringList {
  StringHandler::StringList stringList;
  std::string argumentSplitAtDelimiter;
  std::size_t head = 0;
  std::size_t tail = 0;
  auto delimiters = delimiter.has_value() ? delimiter.value() : std::string(",");

  while (head != std::string::npos) {
    head = line.find_first_not_of(delimiters, head);
    if (head != std::string::npos) {
      tail = line.find_first_of(delimiters, head);
      argumentSplitAtDelimiter = line.substr(head, tail - head);
      stringList.push_back(argumentSplitAtDelimiter);
      head = tail;
    }
  }

  return stringList;
}

auto StringHandler::strip(std::string &line) -> void {
  // replace white space at the front of the string
  std::size_t head = line.find_first_not_of(" \t\r");
  line.replace(0, head, "");
  std::reverse(line.begin(), line.end());

  // replace white space at the end of the string
  head = line.find_first_not_of(" \t\r");
  line.replace(0, head, "");
  std::reverse(line.begin(), line.end());
}

auto StringHandler::splitStringIntoEqualParts(std::string &line, const int numParts) -> StringHandler::StringList {
  auto stringIsDivisibleIntoEqualParts = line.size() % numParts == 0;
  if (!stringIsDivisibleIntoEqualParts)
    throw std::runtime_error("> String is not divisible into equal parts");
  
  StringHandler::StringList result;
  result.resize(numParts);
  for (int i = 0; i < numParts; ++i) {
    result[i] = line.substr(i * line.size() / numParts, line.size() / numParts);
  }
  
  return result;
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