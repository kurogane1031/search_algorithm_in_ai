#ifndef DEPTH_FIRST_SEARCH_NODE_H
#define DEPTH_FIRST_SEARCH_NODE_H

#include <string>
#include <vector>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/ostream.h>
namespace depth_first_search
{
    struct Object
    {
        int idx = 0;
    };

    std::ostream& operator<<(std::ostream& stream, const Object& others);

    class Node
    {
        public:
            Node() = default;
            Node(Object e);

            void setElement(const Object& element);
            void setVisited(bool is_visited);
            void addNeighbour(Node& node);
            void setNeighbour(std::vector<Node>& neighbour);

            Object getElement();
            bool isVisited();
            std::vector<Node> getNeighbour();
        private:
            Object m_element;
            bool m_visited = false;
            std::vector<Node>* p_m_neighbour;
            std::vector<Node> m_neighbour;
    };
}

#endif
