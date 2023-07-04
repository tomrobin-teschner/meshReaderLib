# project configuration
cmake_minimum_required(VERSION 3.16.0)
project(meshReader LANGUAGES CXX)

# use c++17
set(CMAKE_CXX_STANDARD 17)

# define build target, use the same name as the project for executable
add_library(${CMAKE_PROJECT_NAME}Lib STATIC)
add_executable(${CMAKE_PROJECT_NAME}Test "")

# include the root directory of the project for easy header file includes
target_include_directories(${CMAKE_PROJECT_NAME}Lib PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(${CMAKE_PROJECT_NAME}Test PRIVATE ${CMAKE_SOURCE_DIR})

# ensure that mesh folder required for testing is in the same directory as the executable
file(COPY ${CMAKE_SOURCE_DIR}/mesh DESTINATION ${CMAKE_BINARY_DIR})

# add mesh reader library to test executable
target_link_libraries(${CMAKE_PROJECT_NAME}Test PRIVATE ${CMAKE_PROJECT_NAME}Lib)

# traverse source directory and add source files as needed
add_subdirectory(src)
add_subdirectory(tests)
