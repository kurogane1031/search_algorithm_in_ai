#include <matplot/matplot.h>
#include "node.h"
#include "graph.h"
#include "dfs.h"

int main() {

    depth_first_search::Graph graph;

    std::vector<depth_first_search::Node> nodes;
    for(int i = 0; i < 7; ++i)
    {
        depth_first_search::Node n({i+1});
        nodes.push_back(n);
    }


    graph.setNodes(nodes);
    depth_first_search::DFS search;
    search.dfs(graph);

    // std::vector<std::vector<int>> grid_map =
    //     {{3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //      {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    //      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    //      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    //      {0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
    //      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    //      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    //      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    //      {0, 0, 0, 0, 0, 0, 0, 1, 0, 9},
    //      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1}};

    // matplot::heatmap(grid_map);
    // matplot::show();
    return 0;
}
