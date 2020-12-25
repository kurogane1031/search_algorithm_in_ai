add_library(
  libdfs
  node.h
  node.cpp
  graph.h
  graph.cpp
  dfs.h
  dfs.cpp
  )

target_link_libraries(libdfs PUBLIC Matplot++::matplot fmt::fmt)


add_executable(dfs main.cpp)
target_link_libraries(dfs PUBLIC Matplot++::matplot fmt::fmt libdfs)
