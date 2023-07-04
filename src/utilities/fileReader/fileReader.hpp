// (c) 2023 by Tom-Robin Teschner, www.cfd.university 

#ifndef FILEREADER_HPP
#define FILEREADER_HPP

// c++ include headers
#include <filesystem>
#include <fstream>
#include <string>
#include <stdexcept>

// third-party include headers

// project include headers

namespace cfd {
namespace utilities {

/**
* \class FileReader
* \brief Handle file reading to provide access to a file's content
* \ingroup utilities
*
* File reading is not difficult but adds clutter to the code, thus, this class
* handles the reading and closing of a file automatically. It exposes only
* a single method \c getNextLine(line) which takes one argument \c line into
* which the content of the file is copied. The function returns a boolean value
* indicating whether the end of the file has been reached.
*
* Example usage:
* \code
* FileReader fileReader(std::filesystem::path("mesh/mesh2D.vrt"));
* std::string line;
*
* // loop over the file
* while (!fileReader.getNextLine(line)) {
*   std::cout << line << std::endl;
}
* \endcode
*/

class FileReader {
/// \name Custom types used in this class
/// @{

/// @}

/// \name Constructors and destructors
/// @{
public:
  FileReader(std::filesystem::path file);
  ~FileReader();
/// @}

/// \name API interface that exposes behaviour to the caller
/// @{
public:
  auto getNextLine(std::string& line) -> bool;
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
private:
  std::ifstream fileHandle_;
/// @}
};

}// end namespace utilities
}// end namespace cfd

#include "src/utilities/fileReader/fileReader.tpp"

#endif
