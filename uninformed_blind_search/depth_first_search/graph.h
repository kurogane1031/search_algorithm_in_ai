#ifndef GRAPH_H_
#define GRAPH_H_
#include "node.h"
#include <list>
namespace depth_first_search
{
    class Graph
    {
    public:
        Graph() = default;

        void setNodes(std::vector<depth_first_search::Node>& nodes);
        std::vector<depth_first_search::Node> getNodes();
    private:
        std::vector<depth_first_search::Node> m_nodes;
    };
}

#endif // GRAPH_H_
