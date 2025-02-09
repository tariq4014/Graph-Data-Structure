#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

class MinHeap {
public:
    MinHeap(int capacity);
    ~MinHeap();
    void insert(pVERTEX vertex);
    pVERTEX extractMin();
    void decreaseKey(int index, double newKey);
    bool isEmpty() const;

private:
    pHEAP heap;
    void heapify(int index);
    void swap(int i, int j);
};

#endif
