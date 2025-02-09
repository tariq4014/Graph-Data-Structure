#ifndef STACK_H
#define STACK_H

#include "data_structures.h"

class Stack {
public:
    Stack(int capacity);
    ~Stack();
    void push(pVERTEX vertex);
    pVERTEX pop();
    bool isEmpty() const;

private:
    pVERTEX* stack;
    int capacity;
    int top;
};

#endif
