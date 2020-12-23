#ifndef GRAPH_H_
#define GRAPH_H_

#include "node.h"
class Graph
{
    public:
        Graph() = default;
        Graph(int n);

        void setAllNodes(std::vector<Node> nodes);
        void setWeights(int row, int col, double value);

        std::vector<Node> getAllNodes();
        int getMaximumNumberofNodes();
        std::vector<std::vector<double>> getWeights();
        double getWeights(int row, int col);

    private:
        std::vector<Node> m_all_nodes;
        int m_maximum_number_of_nodes = 10;
        std::vector<std::vector<double>> m_weights;
};

#endif // GRAPH_H_
