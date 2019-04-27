#ifndef MEMSTACK_H_
#define MEMSTACK_H_

#include "node.h"

class MemStack
{
    private:
        // Max size of the stack in bytes.
        static const size_t STACK_SIZE = 2048;
        // Max number of items on the stack.
        static const int MAX_NODES = 32;
        // Pairs of address and size of items on the stack.
        Node nodes[MAX_NODES];
        // Index of the top node in nodes, -1 when no items on the stack.
        int topNode;
        // Pointer to the end of the used memory.
        size_t* top;
        // Base address of the allocated memory.
        void* buffer;

    public:
        // Allocates the stack memory and intializes values.
        MemStack();
        // Returns 1 if there are no items on the stack. Returns 0 otherwise.
        bool isEmpty();
        // Reserves size bytes on the stack and returns the starting  address to the reserved memory.
        // Returns nullptr if the item limit is reached or there is not enough memory.
        void* push(size_t size);
        // Reclaims the memory used by the top item on the stack.
        // Returns 1 if the item was successfully popped. Returns 0 othersize.
        bool pop();
        // Returns the starting address of the memory reserved for the top item.
        void* peek();
        // Frees the stack memory.
        ~MemStack();
};
    
#endif
