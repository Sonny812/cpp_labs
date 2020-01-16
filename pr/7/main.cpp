#include "LinkedList.hpp"

int main()
{
    auto list = LinkedList::createFromText("Hello world!");
    list->deleteNodeBySymbol('o');

    auto reversed = list->reverse();
    reversed->output();

    list->clear();
    reversed->clear();

    auto length = list->length();

    delete list;
    delete reversed;
}
