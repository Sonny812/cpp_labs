#include "LinkedList.hpp"

void LinkedList::insert(char ch)
{
    if (this->head == nullptr)
    {
        this->head = new Node(ch, nullptr);
        this->head->setNext(this->head);

        return;
    }

    if (auto node = this->getNodeBySymbol(ch))
    {
        node->increaseCount();

        return;
    }

    auto current = this->head;

    do
    {
        current = current->getNext();
    } while (current->getNext() != head);

    current->setNext(new Node(ch, head));
}

void LinkedList::output(std::ostream &os)
{
    this->traverse([&os](Node *node) {
        os << "Symbol: " << node->getSymbol() << ". Count: " << node->getCount() << std::endl;
    });
}

int LinkedList::length()
{
    int length = 0;

    this->traverse([&length](Node *node) {
        ++length;
    });

    return length;
}

void LinkedList::clear()
{
    if (this->head != nullptr)
    {
        auto current = this->head;

        do
        {
            auto prev = current;
            current = current->getNext();

            delete prev;
        } while (current != this->head);

        this->head = nullptr;
    }
}

void LinkedList::deleteNodeBySymbol(char ch)
{
    this->traverse([this, ch](Node *node) {
        if (node->getNext()->isNodeSymbolEqual(ch))
        {
            auto prev = node;
            auto next = node->getNext()->getNext();
            node = node->getNext();
            prev->setNext(node->getNext());

            if (this->head == node)
            {
                this->head = prev;
            }

            delete node;
            return;
        }
    });
}

Node *LinkedList::getNodeBySymbol(char ch)
{
    Node *foundedNode = nullptr;

    this->traverse([&foundedNode, ch](Node *node) {
        if (node->isNodeSymbolEqual(ch))
        {
            foundedNode = node;
        }
    });

    return foundedNode;
}

LinkedList *LinkedList::reverse()
{
    auto reversedList = new LinkedList();

    this->traverse([&reversedList](Node *node) {
        auto newNode = new Node(node->getSymbol(), reversedList->head, node->getCount());
        auto reversedListCurrent = reversedList->head;

        if (reversedList->head != nullptr)
        {
            while (reversedListCurrent->getNext() != reversedList->head)
            {
                reversedListCurrent = reversedListCurrent->getNext();
            }
            reversedListCurrent->setNext(newNode);
        }
        else
        {
            newNode->setNext(newNode);
        }

        reversedList->head = newNode;
    });

    return reversedList;
}

LinkedList *LinkedList::createFromText(std::string text)
{
    auto list = new LinkedList();

    for (auto symbol : text)
    {
        list->insert(symbol);
    }

    return list;
}

void LinkedList::traverse(std::function<void(Node *)> processNode)
{
    if (this->head == nullptr)
    {
        return;
    }

    auto current = head;

    do
    {
        processNode(current);
        current = current->getNext();
    } while (current != head);
}
