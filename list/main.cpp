#include <stdio.h>
#include "linkedlist.h"

void printList(LinkedList<int>& list)
{
    int length = list.getLength();
    printf("list: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d", list.getItem(i));
    }
    printf("\n");
}

int main()
{
    LinkedList<int> list;
    list.append(7);
    printList(list);
    list.append(8);
    printList(list);
    list.append(9);
    printList(list);
    list.insert(0, 6);
    printList(list);
    return 0;
}

