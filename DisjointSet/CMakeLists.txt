file(GLOB src *.cpp)

list(APPEND header_dirs ${CMAKE_SOURCE_DIR}/Test/Tools/doctest/)
include_directories(${header_dirs})

add_library(DisjointSet ${src})