project(design)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(src)

add_executable(main src/main.cc)

