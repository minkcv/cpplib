#ifndef NODE_H_
#define NODE_H_

template<typename ItemType>
struct Node
{
    ItemType item;
    Node<ItemType>* next;
};


#endif
