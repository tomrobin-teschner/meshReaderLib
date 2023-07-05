# project configuration
cmake_minimum_required(VERSION 3.16.0)
project(meshReader VERSION 1.0.0 LANGUAGES CXX)

# use c++17
set(CMAKE_CXX_STANDARD 17)

# define build target, use the same name as the project for executable
add_library(${CMAKE_PROJECT_NAME} STATIC)

# include the root directory of the project for easy header file includes
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})

# traverse source directory and add source files as needed
add_subdirectory(src)

# enable testing
enable_testing()

# then add tests for ctest separately
add_subdirectory(tests)

# install the library
include(GNUInstallDirs)
install(TARGETS ${CMAKE_PROJECT_NAME}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)