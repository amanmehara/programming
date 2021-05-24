cmake_minimum_required (VERSION 3.19)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ("programming" CXX)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)

add_library(programming)
set_target_properties(programming PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()
add_subdirectory(data_structures)
add_subdirectory(mathematics)
add_subdirectory(randomized_algorithms)
add_subdirectory(sort)
add_subdirectory(test)
