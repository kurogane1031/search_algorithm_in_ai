#include "graph.h"

namespace depth_first_search
{
    void Graph::setNodes(const MAP& nodes)
    {
        m_nodes = nodes;
    }

    MAP Graph::getNodes()
    {
        return m_nodes;
    }
}
