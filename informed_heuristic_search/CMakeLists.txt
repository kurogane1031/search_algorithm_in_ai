add_executable(run node.cpp graph.cpp heuristic.cpp main.cpp)
target_link_libraries(run PUBLIC fmt::fmt Matplot++::matplot)
