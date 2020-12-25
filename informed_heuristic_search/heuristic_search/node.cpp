#include "node.h"

Node::Node(Object element, int index)
    : m_element(element), m_index(index)
{

}

std::ostream& operator<<(std::ostream& stream, const Object &others)
{
    stream << "Name: " << others.m_name << "\tAge:" << others.age;
    return stream;
}

// SETTERS
void Node::setElement(Object element)
{
    m_element = element;
}

void Node::setVisited(bool is_visited)
{
    m_visited = is_visited;
}

void Node::addNeighbour(Node node)
{
    m_neighbours.push_back(node);
}

void Node::setIndex(int index)
{
    m_index = index;
}


// GETTERS
Object Node::getElement()
{
    return m_element;
}

bool Node::checkIfVisited()
{
    return m_visited;
}

std::vector<Node> Node::getNeighbours()
{
    return m_neighbours;
}

int Node::getIndex()
{
    return m_index;
}
