#ifndef BINARY_TREE
#define BINARY_TREE

#include "Node.hpp"

class BinaryTree
{
    private:
        Node* root = nullptr;
    public:
        ~BinaryTree();
        void insert(int value);
        void deleteNode(int value);
        void print();
        void clear();
        int maxDepth();
        int distance(int value);
};

#endif