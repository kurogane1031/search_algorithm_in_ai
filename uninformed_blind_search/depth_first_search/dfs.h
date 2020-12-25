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
            void dfsInStack(depth_first_search::Node& root);
        private:
            std::stack<depth_first_search::Node> m_stacks;
            std::vector<bool> visited;
    };
}

#endif // DEPTH_FIRST_SEARCH_DFS_H_
