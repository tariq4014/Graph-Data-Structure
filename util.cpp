#include "util.h"
#include <iostream>

void initializeVertices(pVERTEX* vertices, int n) {
    for (int i = 1; i <= n; ++i) {
        vertices[i] = new VERTEX();
        vertices[i]->index = i;
        vertices[i]->color = WHITE;
        vertices[i]->key = DBL_MAX;
        vertices[i]->pi = -1;
        vertices[i]->position = i;
    }
}

void freeVertices(pVERTEX* vertices, int n) {
    for (int i = 1; i <= n; ++i) {
        delete vertices[i];
    }
}

void printVertex(pVERTEX vertex) {
    std::cout << "Vertex " << vertex->index
        << ": color=" << vertex->color
        << ", key=" << vertex->key
        << ", pi=" << vertex->pi
        << ", position=" << vertex->position << std::endl;
}
