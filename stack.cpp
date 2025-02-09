//Name: Tariq Alharbi
//ASU ID: 1227159754

#include "stack.h"

Stack::Stack(int capacity) {
    this->capacity = capacity;
    stack = new pVERTEX[capacity];
    top = -1;
}

Stack::~Stack() {
    delete[] stack;
}

void Stack::push(pVERTEX vertex) {
    if (top < capacity - 1) {
        stack[++top] = vertex;
    }
}

pVERTEX Stack::pop() {
    if (isEmpty()) return nullptr;
    return stack[top--];
}

bool Stack::isEmpty() const {
    return top == -1;
}
