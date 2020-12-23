#include "node.h"
#include "graph.h"
#include "heuristic.h"
int main(/*int argc, char *argv[]*/) {
    Object element({"Table", 10});
    Graph g(7);

    std::vector<Node> nodes;
    for(int i = 0; i < 7; ++i)
    {
        nodes.push_back({element, i});
    }

    nodes[0].addNeighbour(nodes[1]);
    g.setWeights(nodes[0].getIndex(), nodes[1].getIndex(), 10);
    nodes[0].addNeighbour(nodes[2]);
    g.setWeights(nodes[0].getIndex(), nodes[2].getIndex(), 2);


    nodes[1].addNeighbour(nodes[3]);
    g.setWeights(nodes[1].getIndex(), nodes[3].getIndex(), 1);
    nodes[1].addNeighbour(nodes[4]);
    g.setWeights(nodes[1].getIndex(), nodes[4].getIndex(), 3);

    nodes[2].addNeighbour(nodes[5]);
    g.setWeights(nodes[2].getIndex(), nodes[5].getIndex(), 20);
    nodes[2].addNeighbour(nodes[6]);
    g.setWeights(nodes[2].getIndex(), nodes[6].getIndex(), 40);

    g.setAllNodes(nodes);
    Heuristic heuristic;
    heuristic.search(g);
    return 0;
}
