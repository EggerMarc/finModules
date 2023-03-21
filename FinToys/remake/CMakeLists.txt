cmake_minimum_required(3.10)

project(finToys)

set(CMAKE_CXX_STANDARD 17) # adds the -std=c++17 flag on all the compilation lines
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # important, generates a json file with all the build scripts


add_library(under under.cpp)
add_library(product product.cpp)
add_executable(main main.cpp)
target_link_libraries(main under product)