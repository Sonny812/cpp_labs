#include "BinaryTree.hpp"
#include <iostream>
#include <iomanip>
#include <functional>

BinaryTree::~BinaryTree()
{
    this->clear();
}

void BinaryTree::insert(int value)
{
    std::function<void(Node *&, int)> insert = [&insert](Node *&node, int value) {
        if (node == nullptr)
        {
            node = new Node(value);
            return;
        }

        if (value <= node->data)
        {
            insert(node->left, value);
        }
        else
        {
            insert(node->right, value);
        }
    };

    insert(this->root, value);
}

void BinaryTree::deleteNode(int value)
{
    std::function<void(Node *&, int)> deleteNode = [&deleteNode](Node *&node, int value) {
        if (node == nullptr)
        {
            return;
        }

        if (value < node->data)
        {
            deleteNode(node->left, value);
        }
        else if (value > node->data)
        {
            deleteNode(node->right, value);
        }
        else
        {
            if (node->left == nullptr && node->right == nullptr) // node without childs
            {
                delete node;
                node = nullptr;
            }
            else if (node->left == nullptr) // only right child exist
            {
                auto temp = node->right;
                delete node;
                node = temp;
            }
            else if (node->right == nullptr) // only left child exist
            {
                auto temp = node->left;
                delete node;
                node = temp;
            }
            else // both children exist
            {
                auto temp = node->right;
                while (temp->left != nullptr)
                {
                    temp = temp->left;
                }
                node->data = temp->data;

                deleteNode(node->right, temp->data);
            }
        }
    };

    deleteNode(this->root, value);
}

void BinaryTree::print()
{
    std::function<void(Node *, int)> print = [&print](Node *node, int depth) {
        if (node != nullptr)
        {
            print(node->right, depth + 1);
            std::cout << std::setw(depth * 2) << node->data << std::endl;
            print(node->left, depth + 1);
        }
    };

    print(this->root, 1);
}

void BinaryTree::clear()
{
    std::function<void(Node *&)> clear = [&clear](Node *&node) {
        if (node != nullptr)
        {
            clear(node->left);
            clear(node->right);

            delete node;

            node = nullptr;
        }
    };

    clear(this->root);
}

int BinaryTree::maxDepth()
{
    std::function<int(Node *)> maxDepth = [&maxDepth](Node *node) -> int {
        if (node == nullptr)
        {
            return 0;
        }
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        auto max = lDepth >= rDepth ? lDepth : rDepth;

        return max + 1;
    };

    return maxDepth(this->root);
}

int BinaryTree::distance(int value)
{
    std::function<int(Node *, int, int)> distance = [&distance](Node *node, int value, int level) {
        if (node == nullptr)
        {
            return -1;
        }

        if (node->data == value)
        {
            return level;
        }

        int lDistance = distance(node->left, value, level + 1);

        return lDistance != -1 ? lDistance : distance(node->right, value, level + 1);
    };

    return distance(this->root, value, 0);
}