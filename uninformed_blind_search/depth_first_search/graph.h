#ifndef GRAPH_H_
#define GRAPH_H_
#include "node.h"
#include <unordered_map>
namespace depth_first_search
{
    using MAP = std::unordered_map<int, depth_first_search::Node>;
    class Graph
    {
        public:
            Graph() = default;
            void setNodes(const MAP& nodes);
            MAP getNodes();
        public:
            MAP m_nodes;
    };
}

#endif // GRAPH_H_
