# project configuration
cmake_minimum_required(VERSION 3.16.0)
project(meshReader VERSION 1.0.0 LANGUAGES CXX)

# use c++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

# set option to build documentation
option(BUILD_DOC "Build documentation" OFF)

# use doxygen for building the documentation, check that it is available
find_package(Doxygen)

if (BUILD_DOC)
  if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${PROJECT_SOURCE_DIR}/docs/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_BINARY_DIR}/Doxyfile)

    # set doxygen related variables that will be substituted in the template
    set(DOXYGEN_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target(doc_doxygen ALL
      COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      COMMENT "Generating API documentation with Doxygen"
    )
  else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
  endif (DOXYGEN_FOUND)
endif (BUILD_DOC)

set(HEADERS "// top level include file for ${PROJECT_NAME}\n")
get_target_property(TARGET_SOURCES ${CMAKE_PROJECT_NAME} SOURCES)
foreach(SOURCE ${TARGET_SOURCES})
  get_filename_component(EXTENSION ${SOURCE} EXT)
  if(EXTENSION STREQUAL ".hpp")
    string(REPLACE ${PROJECT_SOURCE_DIR}/ "" RELATIVE_SOURCE ${SOURCE})
    list(APPEND HEADERS "#include \"${RELATIVE_SOURCE}\"\n")
  endif()
endforeach()

set(HEADER_MASTER ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}.hpp)
file(WRITE ${HEADER_MASTER} ${HEADERS})

# install the library
include(GNUInstallDirs)
install(TARGETS ${CMAKE_PROJECT_NAME}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(DIRECTORY "${CMAKE_SOURCE_DIR}/src/"
  DESTINATION "include/${PROJECT_NAME}/src"
  FILES_MATCHING
  PATTERN "*.hpp"
  PATTERN "*.tpp"
)

install(FILES ${HEADER_MASTER}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)