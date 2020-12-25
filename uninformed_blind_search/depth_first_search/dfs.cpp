#include "dfs.h"
#include <algorithm>
#include <fmt/ranges.h>
namespace depth_first_search
{
    void DFS::dfs(depth_first_search::Graph& graph)
    {
        m_nodes = graph.getNodes();


        for(int i = 0; i < (int)m_nodes.size(); ++i)
        {
            if(!m_nodes[i].isVisited())
            {
                m_nodes[i].setVisited(true);
                dfsInStack(i);
            }
        }
    }

    void DFS::dfsInStack(int root_key)
    {
        m_stacks.push(root_key);
        m_nodes[root_key].setVisited(true);

        while(!m_stacks.empty())
        {
            int current_node_idx = m_stacks.top();
            m_stacks.pop();

            fmt::print("Current node: {} Visited? {}\n", m_nodes[current_node_idx].getElement(), m_nodes[current_node_idx].isVisited());
            auto number_of_neighbours = m_nodes[current_node_idx].getNeighbourKeyList().size();

            std::vector<int> neighbour_key = m_nodes[current_node_idx].getNeighbourKeyList();
            for(int i = number_of_neighbours - 1; i >= 0; --i)
            {
                if(!m_nodes[neighbour_key[i]].isVisited())
                {
                    m_nodes[neighbour_key[i]].setVisited(true);
                    m_stacks.push(neighbour_key[i]);
                }
            }
        }
    }
}
