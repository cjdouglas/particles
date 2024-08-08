cmake_minimum_required(VERSION 3.28)

project(particles VERSION 1.0.0 DESCRIPTION "Maybe a particle simulator, we'll see how far I get" LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchDependencies)
include(CompileFlags)
add_subdirectory(glad)

add_executable(particles)
target_sources(particles PRIVATE
  src/main.cc
  src/graphics/window.cc)
target_include_directories(particles PRIVATE include)
target_link_libraries(particles glfw glad)
apply_compilation_flags(particles)
