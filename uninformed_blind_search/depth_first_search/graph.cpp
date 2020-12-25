#include "graph.h"

namespace depth_first_search
{
    void Graph::setNodes(std::vector<depth_first_search::Node>& nodes)
    {
        m_nodes = nodes;
    }

    std::vector<depth_first_search::Node> Graph::getNodes()
    {
        return m_nodes;
    }
}
