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
            void dfsInStack(int root_key);
        private:
            std::stack<int> m_stacks;
            depth_first_search::MAP m_nodes;
    };
}

#endif // DEPTH_FIRST_SEARCH_DFS_H_
