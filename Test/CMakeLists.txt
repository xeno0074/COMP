list(APPEND doctest_dir ${CMAKE_SOURCE_DIR}/Test/Tools/doctest/)
list(APPEND inc_dir ${doctest_dir})

include_directories(${inc_dir})

file(GLOB arraySrc ${CMAKE_SOURCE_DIR}/Array/*.cpp)
list(APPEND src ${arraySrc} )
# add_library(Array ${src})

file(GLOB treeSrc ${CMAKE_SOURCE_DIR}/Tree/*.cpp)
list(APPEND src ${treeSrc})

file(GLOB trieSrc ${CMAKE_SOURCE_DIR}/Trie/*.cpp)
list(APPEND src ${trieSrc})

message(src=${src})

add_executable(Comp Test.cpp ${src})

# target_link_libraries(Comp Array)