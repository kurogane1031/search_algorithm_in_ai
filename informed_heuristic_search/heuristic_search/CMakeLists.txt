add_library(
  libheuristic_search
  node.h
  node.cpp
  graph.h
  graph.cpp
  heuristic.h
  heuristic.cpp
  )

target_link_libraries(libheuristic_search PRIVATE Matplot++::matplot fmt::fmt)

add_executable(run main.cpp)
target_link_libraries(run PRIVATE fmt::fmt Matplot++::matplot libheuristic_search)
