#include <iostream>
#include <functional>
#include "Node.hpp"

#ifndef LINKED_LIST
#define LINKED_LIST


class LinkedList
{
    private:
        Node *head = nullptr;
        void traverse(std::function<void(Node*)>);
    public:
        void insert(char ch);
        void output(std::ostream &os = std::cout);
        int length();
        void clear();
        void deleteNodeBySymbol(char ch);
        Node* getNodeBySymbol(char ch);
        LinkedList* reverse();
        static LinkedList* createFromText(std::string text);
};

#endif
