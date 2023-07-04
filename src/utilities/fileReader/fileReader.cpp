// (c) 2023 by Tom-Robin Teschner, www.cfd.university 

// project include headers
#include "src/utilities/fileReader/fileReader.hpp"

namespace cfd {
namespace utilities {

/// \name Constructors and destructors
/// @{
FileReader::FileReader(std::filesystem::path file) {
  fileHandle_.open(file);
  if (!fileHandle_.is_open())
    throw std::runtime_error(std::string("Could not open file: " + *file.c_str()));
}

FileReader::~FileReader() {
  if (fileHandle_.is_open())
    fileHandle_.close();
}
/// @}

/// \name API interface that exposes behaviour to the caller
/// @{
auto FileReader::getNextLine(std::string& line) -> bool {
  std::getline(fileHandle_, line);
  return !fileHandle_.eof();
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