#include <matplot/matplot.h>
#include "node.h"
#include "graph.h"
#include "dfs.h"
#include "maze.h"

int main() {

    // depth_first_search::Graph graph;

    // depth_first_search::MAP nodes;
    // for(int i = 0; i < 7; ++i)
    // {
    //     char alphabet = 'a';
    //     alphabet += i;
    //     depth_first_search::Node n({alphabet, i, i});
    //     nodes[i] = n;
    // }

    // nodes[0].addNeighbourKey(1);
    // nodes[0].addNeighbourKey(2);
    // nodes[1].addNeighbourKey(3);
    // nodes[1].addNeighbourKey(4);
    // nodes[2].addNeighbourKey(5);
    // nodes[2].addNeighbourKey(6);

    // graph.setNodes(nodes);
    // depth_first_search::DFS search;
    // search.dfs(graph);
    std::vector<std::vector<int>> map =
        {{1, 1,1,1,1,1,1,1,1,1,1,1,1},
         {1,-1,1,0,1,0,1,0,0,0,0,0,1},
         {1, 0,1,0,0,0,1,0,1,1,1,0,1},
         {1, 0,0,0,1,1,1,0,0,0,0,0,1},
         {1, 1,1,0,0,0,0,0,1,1,1,0,1},
         {1, 0,1,1,1,1,1,0,1,0,0,0,1},
         {1, 0,1,0,1,0,0,0,1,1,1,0,1},
         {1, 0,1,0,1,1,1,0,1,0,1,0,1},
         {1, 0,0,0,0,0,0,0,0,0,1,9,1},
         {1, 1,1,1,1,1,1,1,1,1,1,1,1}};
    depth_first_search::Maze maze(map);
    maze.searchPath();
    maze.plotMaze();
    return 0;
}
