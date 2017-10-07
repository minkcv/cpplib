#include "memstack.h"
#include <stdio.h>
#include <stdlib.h>

MemStack::MemStack()
{
    topNode = -1;
    buffer = malloc(STACK_SIZE);
    top = (size_t*)buffer;
    printf("base address of the stack is %p\n", buffer);
}

bool MemStack::isEmpty()
{
    return topNode < 0;
}

void* MemStack::push(size_t size)
{
    if (top + size > (size_t*)buffer + STACK_SIZE)
    {
        printf("stack overflow\n");
        return nullptr;
    }
    if (topNode > MAX_NODES)
    {
        printf("stack item limit reached\n");
        return nullptr;
    }
    topNode++;
    nodes[topNode].data = top;
    nodes[topNode].size = size;
    top += size;
    printf("== PUSH ==\n");
    printf("pushing %zu bytes onto the stack\n", size);
    printf("top of the stack is now %p\n", (void*)top);
    printf("%zu bytes are currently on the stack\n", top - (size_t*)buffer);
    return top;
}

bool MemStack::pop()
{
    if (isEmpty())
    {
        printf("can't pop while stack is empty\n");
        return 0;
    }
    top -= nodes[topNode].size;
    printf("== POP ==\n");
    printf("popping %zu bytes off the stack\n", nodes[topNode].size);
    printf("top of the stack is now %p\n", (void*)top);
    printf("%zu bytes are currently on the stack\n", top - (size_t*)buffer);
    topNode--;
    return 1;
}

void* MemStack::peek()
{
    if (! isEmpty())
        return nodes[topNode].data;
    printf("stack is empty\n");
    return nullptr;
}

MemStack::~MemStack()
{
    while (! isEmpty())
        pop();

    free(buffer);
    buffer = nullptr;
    top = nullptr;
}
