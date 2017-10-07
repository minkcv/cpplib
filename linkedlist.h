#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "ilist.h"
#include "node.h"

template<typename ItemType>
class LinkedList : public IList<ItemType>
{
    private:
        Node<ItemType>* headPtr;

        int length;

        Node<ItemType>* getNodeAt(int position) const;
    public:
        LinkedList();
        LinkedList(const LinkedList<ItemType>& list);
        virtual ~LinkedList();

        bool isEmpty() const;
        int getLength() const;
        bool insert(int position, const ItemType& item);
        bool append(const ItemType& item);
        bool removeAt(int position);
        void clear();

        ItemType getItem(int position) const;
};

#include "linkedlist.cpp"

#endif
