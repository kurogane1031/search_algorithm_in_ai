cmake_minimum_required(VERSION 3.18)
project(search_algorithm_in_ai)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_FLAGS "-g -Wall -Wno-conversion -Wextra -Wpedantic -ftime-trace")
SET(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

list(APPEND CMAKE_PREFIX_PATH "/home/zulfaqar/develop/libraries/matplotplusplus/install/")

option (FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." TRUE)

if (${FORCE_COLORED_OUTPUT})
  if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options (-fdiagnostics-color=always)
  elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options (-fcolor-diagnostics)
  endif ()
endif()

find_package(Matplot++)
find_package(FMT)

add_subdirectory(uninformed_blind_search)
# add_subdirectory(informed_heuristic_search)
