target_sources(${CMAKE_PROJECT_NAME} PRIVATE meshReaderBase.cpp PUBLIC meshReaderBase.hpp)
set_property(TARGET ${CMAKE_PROJECT_NAME} APPEND PROPERTY PUBLIC_HEADER ${CMAKE_CURRENT_SOURCE_DIR}/meshReaderBase.hpp)
