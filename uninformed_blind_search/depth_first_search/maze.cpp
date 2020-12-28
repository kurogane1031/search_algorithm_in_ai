#include "maze.h"

namespace depth_first_search
{
    int Maze::computeIndex(const int &row, const int &column)
    {
        return column + row * m_column_number;
    }

    Maze::Maze(const std::vector<std::vector<int>>& maze)
        : m_maze(maze)
    {
        m_row_number = maze.size();
        m_column_number = maze[0].size();

        m_nodes_matrix.resize(m_row_number, std::vector<depth_first_search::Node>(m_column_number));
    }

    bool Maze::checkIfInMazeBoundary(const int &row, const int &column)
    {
        if(row < 0 || column < 0 || row > m_row_number - 1 || column > m_column_number -1)
        {
            return false;
        }
        return true;
    }

    void Maze::findAndAddNeighbours(const int &row, const int &column)
    {
        if(checkIfInMazeBoundary(row, column+1))
            m_nodes_matrix[row][column].addNeighbourKey(computeIndex(row, column + 1));
        if(checkIfInMazeBoundary(row + 1, column))
            m_nodes_matrix[row][column].addNeighbourKey(computeIndex(row + 1, column));
        if(checkIfInMazeBoundary(row, column-1))
            m_nodes_matrix[row][column].addNeighbourKey( computeIndex(row, column - 1));
        if(checkIfInMazeBoundary(row - 1, column))
            m_nodes_matrix[row][column].addNeighbourKey(computeIndex(row - 1, column));
    }
    void Maze::createGraph()
    {
        std::unordered_map<int, depth_first_search::Node> nodes;
        for(int row = 0; row < m_row_number; ++row)
        {
            for(int col = 0; col < m_column_number; ++col)
            {
                int idx = computeIndex(row, col);
                if(m_maze[row][col] == 1)
                {
                    m_nodes_matrix[row][col].setVisited(true);
                }
                if(m_maze[row][col] == -1)
                {
                    m_start_pos_index = idx;
                }
                if(m_maze[row][col] == 9)
                {
                    m_goal_pos_index = idx;
                }
                findAndAddNeighbours(row, col);
                m_nodes_matrix[row][col].setElement({idx, row, col});
                nodes[idx] = m_nodes_matrix[row][col];
            }
        }
        m_graph.setNodes(nodes);
    }

    void Maze::searchPath()
    {
        createGraph();
        depth_first_search::DFS search;
        search.dfs(m_graph, m_start_pos_index, m_goal_pos_index);
        std::vector<int> nodes_visited = search.getVisitedNodes();
        fmt::print("start: {}, goal: {}\n", m_start_pos_index, m_goal_pos_index);
        for(auto& n:nodes_visited)
        {
            int mark_row = m_graph.getNodes()[n].getElement().row;
            int mark_col = m_graph.getNodes()[n].getElement().col;
            m_maze[mark_row][mark_col] = 5;
        }
    }
    void Maze::plotMaze()
    {
        matplot::heatmap(m_maze);
        matplot::grid(matplot::on);
        matplot::show();

    }
}
