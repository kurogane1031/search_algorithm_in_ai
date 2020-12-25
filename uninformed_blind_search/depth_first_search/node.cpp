#include "node.h"

namespace depth_first_search
{
    std::ostream& operator<<(std::ostream& stream, const Object& others)
    {
        stream << others.idx;
        return stream;
    }

    Node::Node(Object e)
        : m_element(e)
    {}

    void Node::setElement(const Object& element)
    {
        m_element = element;
    }

    void Node::setVisited(bool is_visited)
    {
        m_visited = is_visited;
    }

    void Node::addNeighbour(Node& node)
    {
        m_neighbour.push_back(node);
    }

    void Node::setNeighbour(std::vector<Node>& neighbour)
    {
        m_neighbour = neighbour;
    }

    Object Node::getElement()
    {
        return m_element;
    }

    bool Node::isVisited()
    {
        return m_visited;
    }

    std::vector<Node> Node::getNeighbour()
    {
        return m_neighbour;
    }
}
