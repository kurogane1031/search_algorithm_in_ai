#ifndef MAZE_H_
#define MAZE_H_
#include "dfs.h"
#include "matplot/matplot.h"
namespace depth_first_search
{
    class Maze
    {
        public:
            Maze() = default;
            Maze(const std::vector<std::vector<int>>& maze);
            int computeIndex(const int& row, const int &column);
            bool checkIfInMazeBoundary(const int &row, const int &column);
            void findAndAddNeighbours(const int &row, const int &column);
            void createGraph();
            void searchPath();
            void plotMaze();
        private:
            std::vector<std::vector<int>> m_maze =
            {{1, 1,1,1,1,1,1,1,1,1,1,1,1},
             {1,-1,1,0,1,0,1,0,0,0,0,0,1},
             {1, 0,1,0,0,0,1,0,1,1,1,0,1},
             {1, 0,0,0,1,1,1,0,0,0,0,0,1},
             {1, 1,1,0,0,0,0,0,1,1,1,0,1},
             {1, 0,1,1,1,1,1,0,1,0,0,0,1},
             {1, 0,1,0,1,0,0,0,1,1,1,0,1},
             {1, 0,1,0,1,1,1,0,1,0,1,0,1},
             {1, 0,0,0,0,0,0,0,0,0,1,9,1},
             {1, 1,1,1,1,1,1,1,1,1,1,1,1}};
            std::vector<std::vector<int>> m_index_matrix;
            std::vector<std::vector<depth_first_search::Node>> m_nodes_matrix;
            depth_first_search::Graph m_graph;
            int m_row_number = 0;
            int m_start_pos_index = 0;
            int m_goal_pos_index = 0;
            int m_column_number = 0;
            // int m_block_size = 0;
    };
}
#endif // MAZE_H_
