#ifndef LINKED_LIST_CPP_
#define LINKED_LIST_CPP_

#include "linkedlist.h"

template<typename ItemType>
LinkedList<ItemType>::LinkedList()
{

}

template<typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& list)
{

}

template<typename ItemType>
Node<ItemType> LinkedList<ItemType>::getNodeAt(int position) const
{

}

template<typename ItemType>
bool LinkedList<ItemType>::isEmpty() const
{

}

template<typename ItemType>
int LinkedList<ItemType>::getLength() const
{
    return itemCount;
}

template<typename ItemType>
bool LinkedList<ItemType>::insert(int position, const ItemType& item)
{

}

template<typename ItemType>
bool LinkedList<ItemType>::append(const ItemType& item)
{

}

template<typename ItemType>
bool LinkedList<ItemType>::removeAt(int position)
{

}

template<typename ItemType>
void LinkedList<ItemType>::clear()
{

}

template<typename ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{

}

template<typename ItemType>
LinkedList<ItemType>::~LinkedList()
{

}

#endif
