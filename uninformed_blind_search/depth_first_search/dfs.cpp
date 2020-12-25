#include "dfs.h"
#include <algorithm>
#include <fmt/ranges.h>
namespace depth_first_search
{
    void DFS::dfs(depth_first_search::Graph& graph)
    {
        std::vector<depth_first_search::Node> nodes = graph.getNodes();
        nodes[0].addNeighbour(nodes[1]);
        nodes[0].addNeighbour(nodes[2]);
        nodes[1].addNeighbour(nodes[3]);
        nodes[1].addNeighbour(nodes[4]);
        nodes[2].addNeighbour(nodes[5]);
        nodes[2].addNeighbour(nodes[6]);
        for(auto n:nodes)
        {
            fmt::print("is n{} visited? {}\n", n.getElement(), n.isVisited());
            if(!n.isVisited())
            {
                n.setVisited(true);
                dfsInStack(n);
            }
        }
    }

    void DFS::dfsInStack(depth_first_search::Node& root)
    {
        m_stacks.push(root);
        root.setVisited(true);

        while(!m_stacks.empty())
        {
            depth_first_search::Node current_node = m_stacks.top();
            m_stacks.pop();

            fmt::print("Current node: {} Visited? {}\n", current_node.getElement(), current_node.isVisited());

            std::vector<depth_first_search::Node> neighbour = current_node.getNeighbour();
            std::transform(neighbour.rbegin(),
                           neighbour.rend(),
                           neighbour.rbegin(),
                           [&](depth_first_search::Node& n)
                           {
                               if(!n.isVisited())
                               {
                                   n.setVisited(true);
                                   m_stacks.push(n);
                               }
                               return n;
                           });
        }
    }
}
