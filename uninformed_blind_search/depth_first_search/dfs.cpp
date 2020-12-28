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

    void DFS::dfs(depth_first_search::Graph &graph,
                  const int &start_pos_idx,
                  const int &goal_pos_idx)
    {
        m_start_pos = start_pos_idx;
        m_goal_pos = goal_pos_idx;
        m_nodes = graph.getNodes();

        dfsSearchPath(start_pos_idx);
    }

    void DFS::dfsInStack(const int &root_key)
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

    void DFS::dfsSearchPath(const int &root_key)
    {
        m_stacks.push(root_key);
        m_nodes[root_key].setVisited(true);
        while(!m_stacks.empty())
        {
            int current_node_idx = m_stacks.top();
            m_stacks.pop();
            if(current_node_idx == m_goal_pos)
            {
                m_goal_found = true;
                return;
            }
            else
            {
                m_visited_nodes.push_back(current_node_idx);
            }

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

    std::vector<int> DFS::getVisitedNodes()
    {
        return m_visited_nodes;
    }

    int DFS::getStartPosIndex()
    {
        return m_start_pos;
    }

    int DFS::getGoalPosIndex()
    {
        return m_goal_pos;
    }

    depth_first_search::MAP DFS::getNodes()
    {
        return m_nodes;
    }
}
