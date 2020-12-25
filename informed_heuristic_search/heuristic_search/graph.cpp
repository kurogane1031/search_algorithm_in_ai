#include "graph.h"

Graph::Graph(int n)
    : m_maximum_number_of_nodes(n)
{
    std::vector<std::vector<double>> weight(n, std::vector<double>(n, 0));
    m_weights = weight;
}

void Graph::setAllNodes(std::vector<Node> nodes)
{
    m_all_nodes = nodes;
}

void Graph::setWeights(int row, int col, double value)
{
    if(row >= m_maximum_number_of_nodes || col >= m_maximum_number_of_nodes)
    {
        throw std::runtime_error("Parameter row/col is more than max index");
        return;
    }
    m_weights[row][col] = value;
    m_weights[col][row] = m_weights[row][col];
}

std::vector<Node> Graph::getAllNodes()
{
    return m_all_nodes;
}

int Graph::getMaximumNumberofNodes()
{
    return m_maximum_number_of_nodes;
}

std::vector<std::vector<double>> Graph::getWeights()
{
    return m_weights;
}

double Graph::getWeights(int row, int col)
{
    return m_weights[row][col];
}
