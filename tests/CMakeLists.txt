# ensure that mesh folder required for testing is in the same directory as the executable
file(COPY ${CMAKE_SOURCE_DIR}/mesh DESTINATION ${CMAKE_BINARY_DIR}/tests)

# define a function that can be used to add tests automatically
function (create_test name)
  add_executable(${name} ${name}.cpp)
  target_link_libraries(${name} ${CMAKE_PROJECT_NAME})
  target_include_directories(${name} PRIVATE ${CMAKE_SOURCE_DIR})
  add_test(NAME ${name} COMMAND $<TARGET_FILE:${name}>)
endfunction()

# add tests for star-cd mesh file reading
create_test(starCDReadCoordinates2DTest)
create_test(starCDReadCoordinates3DTest)
create_test(starCDReadCells2DTest)
create_test(starCDReadCells3DTest)
create_test(starCDReadBoundaries2DTest)
create_test(starCDReadBoundaries3DTest)
