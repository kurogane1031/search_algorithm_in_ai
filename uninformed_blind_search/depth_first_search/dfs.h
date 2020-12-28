#ifndef DEPTH_FIRST_SEARCH_DFS_H_
#define DEPTH_FIRST_SEARCH_DFS_H_

#include "node.h"
#include "graph.h"
#include <stack>
namespace depth_first_search
{
    class DFS
    {
        public:
            DFS() = default;
            void dfs(depth_first_search::Graph& graph);
            void dfs(depth_first_search::Graph& graph,
                     const int& start_pos_idx,
                     const int& goal_pos_idx);
            void dfsInStack(const int &root_key);
            void dfsSearchPath(const int &root_key);
            std::vector<int> getVisitedNodes();
            int getStartPosIndex();
            int getGoalPosIndex();
            depth_first_search::MAP getNodes();
        private:
            std::stack<int> m_stacks;
            depth_first_search::MAP m_nodes;
            std::vector<int> m_visited_nodes;
            int m_start_pos = 0;
            int m_goal_pos = 0;
            bool m_goal_found = false;
    };
}

#endif // DEPTH_FIRST_SEARCH_DFS_H_
