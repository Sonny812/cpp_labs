#include <iostream>
#include <random>
#include "BinaryTree.hpp"

const int SIZE = 10;
const int NUMBERS[SIZE] = {0, 3, 1, 11, 19, 13, 5, 17, 24, 17};

int main()
{
    auto tree = BinaryTree();

    for (int i = 0; i < SIZE; i++)
    {
        tree.insert(NUMBERS[i]);
    }
    tree.deleteNode(19);
    tree.print();

    std::cout << std::endl;
    std::cout << "Max depth is: " << tree.maxDepth() << std::endl;
    std::cout << "Distance to 5 is: " << tree.distance(5) << std::endl;

    tree.clear();
}