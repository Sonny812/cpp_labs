#ifndef NODE
#define NODE

class Node
{
    private:
        char symbol;
        int count;
        Node *next;

    public:
        Node(char ch, Node *next, int count = 1): symbol(ch), next(next), count(count) {};
        bool isNodeSymbolEqual(char ch);
        void increaseCount();
        char getSymbol();
        int getCount();
        Node* getNext();
        Node* setNext(Node *node);
};

#endif