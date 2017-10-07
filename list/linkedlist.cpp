#ifndef LINKED_LIST_CPP_
#define LINKED_LIST_CPP_

#include <stdio.h>
#include "linkedlist.h"

template<typename ItemType>
LinkedList<ItemType>::LinkedList() : length(0), headPtr(nullptr)
{
}

template<typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& list) : length(list.getLength())
{

}

template<typename ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
    if (position > length || position < 0)
        return nullptr;

    Node<ItemType>* node = headPtr;
    for (int i = 0; i < position; i++)
    {
        if (node == nullptr)
            return nullptr;
        node = node->next;
    }
    return node;
}

template<typename ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
    return length == 0;
}

template<typename ItemType>
int LinkedList<ItemType>::getLength() const
{
    return length;
}

template<typename ItemType>
bool LinkedList<ItemType>::insert(int position, const ItemType& item)
{
    if (position > length + 1 || position < 0)
        return false;

    Node<ItemType>* newNode = new Node<ItemType>();
    newNode->item = item;
    newNode->next = nullptr;
    if (headPtr == nullptr || position == 0)
    {
        Node<ItemType>* currentNode = headPtr;
        headPtr = newNode;
        newNode->next = currentNode;
        length++;
        return true;
    }
    Node<ItemType>* prevNode = getNodeAt(position - 1);
    if (prevNode != nullptr)
    {
        Node<ItemType>* nextNode = prevNode->next;
        prevNode->next = newNode;
        newNode->next = nextNode;
        length++;
        return true;
    }
    return false;
}

template<typename ItemType>
bool LinkedList<ItemType>::append(const ItemType& item)
{
    return insert(length, item);
}

template<typename ItemType>
bool LinkedList<ItemType>::removeAt(int position)
{
    if (position > length || position < 0 || headPtr == nullptr)
        return false;

    if (position == 0)
    {
        Node<ItemType>* removedNode = headPtr;
        headPtr = removedNode->next;
        delete removedNode;
        removedNode = nullptr;
        length--;
        return true;
    }

    Node<ItemType>* previousNode = getNodeAt(position - 1);
    if (previousNode == nullptr)
        return false;


    Node<ItemType>* removedNode = previousNode->next;
    previousNode->next = previousNode->next->next;
    delete removedNode;
    removedNode = nullptr;
    length--;
    return true;
}

template<typename ItemType>
void LinkedList<ItemType>::clear()
{
    while (length > 0)
        removeAt(0);
}

template<typename ItemType>
ItemType LinkedList<ItemType>::getItem(int position) const
{
    Node<ItemType>* node = getNodeAt(position);
    if (node == nullptr)
        printf("Index out of bounds\n");
    return node->item;
}

template<typename ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}

#endif
