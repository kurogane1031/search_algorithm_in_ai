#include "heuristic.h"
#include <numeric>
void Heuristic::search(Graph graph)
{
    auto nodes = graph.getAllNodes();
    Node root = nodes[0];

    std::vector<Node> neighbours;

    fmt::print("Shorted route\n");
    do{
        neighbours = root.getNeighbours();
        fmt::print("Index: {}, Object information : {}\n", root.getIndex(), root.getElement());

        double min = std::numeric_limits<int>::max();
        int idx = 1;
        for(auto n:neighbours)
        {
            double cost = graph.getWeights(root.getIndex(), n.getIndex());
            if(cost < min)
            {
                min = cost;
                idx = n.getIndex();
            }
        }
        root = nodes[idx];
    }while(neighbours.size());
}
