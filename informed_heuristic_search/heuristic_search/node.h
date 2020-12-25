#ifndef NODE_H_
#define NODE_H_
#include <vector>
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <fmt/format.h>
#include <matplot/matplot.h>
#include <string>
struct Object
{
    std::string m_name;
    int age = 0;
};

std::ostream& operator<<(std::ostream& stream, const Object &others);

class Node
{
    public:
        Node() = default;
        Node(Object element, int index);

        void setElement(Object element);
        void setVisited(bool is_visited);
        void addNeighbour(Node node);
        void setIndex(int index);

        Object getElement();
        bool checkIfVisited();
        std::vector<Node> getNeighbours();
        int getIndex();
    private:
        Object m_element;
        bool m_visited = false;
        std::vector<Node> m_neighbours;
        int m_index = 0;
};
#endif
