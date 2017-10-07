#include <stdio.h>
#include "linkedlist.h"

int main()
{
    LinkedList<int> list;
    list.append(7);
    printf("list length: %d\n", list.getLength());
    int item = list.getItem(0);
    printf("item 0: %d\n", item);
    return 0;
}
    
