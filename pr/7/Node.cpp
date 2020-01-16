#include "Node.hpp"

bool Node::isNodeSymbolEqual(char ch)
{
    return this->symbol == ch;
}

void Node::increaseCount()
{
    ++this->count;
}

char Node::getSymbol()
{
    return this->symbol;
}

int Node::getCount()
{
    return this->count;
}

Node *Node::getNext()
{
    return this->next;
}

Node *Node::setNext(Node* node)
{
    this->next = node;

    return this;
}