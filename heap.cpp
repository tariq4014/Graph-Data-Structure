#include "heap.h"
#include <algorithm>

MinHeap::MinHeap(int capacity) {
    heap = new HEAP;
    heap->capacity = capacity;
    heap->size = 0;
    heap->H = new pELEMENT[capacity + 1];
}

MinHeap::~MinHeap() {
    delete[] heap->H;
    delete heap;
}

void MinHeap::insert(pVERTEX vertex) {
    if (heap->size == heap->capacity) return;
    heap->size++;
    int i = heap->size;
    heap->H[i] = vertex;
    while (i > 1 && heap->H[i / 2]->key > heap->H[i]->key) {
        swap(i, i / 2);
        i = i / 2;
    }
}

pVERTEX MinHeap::extractMin() {
    if (isEmpty()) return nullptr;
    pVERTEX min = heap->H[1];
    heap->H[1] = heap->H[heap->size];
    heap->size--;
    heapify(1);
    return min;
}

void MinHeap::decreaseKey(int index, double newKey) {
    heap->H[index]->key = newKey;
    while (index > 1 && heap->H[index / 2]->key > heap->H[index]->key) {
        swap(index, index / 2);
        index = index / 2;
    }
}

bool MinHeap::isEmpty() const {
    return heap->size == 0;
}

void MinHeap::heapify(int index) {
    int smallest = index;
    int left = 2 * index;
    int right = 2 * index + 1;
    if (left <= heap->size && heap->H[left]->key < heap->H[smallest]->key) {
        smallest = left;
    }
    if (right <= heap->size && heap->H[right]->key < heap->H[smallest]->key) {
        smallest = right;
    }
    if (smallest != index) {
        swap(index, smallest);
        heapify(smallest);
    }
}

void MinHeap::swap(int i, int j) {
    std::swap(heap->H[i], heap->H[j]);
    heap->H[i]->position = i;
    heap->H[j]->position = j;
}
