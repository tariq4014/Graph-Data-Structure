#pragma once
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <cfloat>

enum COLOR { WHITE, GRAY, BLACK };

typedef struct TAG_VERTEX {
    int index;
    COLOR color;
    double key;
    int pi;
    int position;
} VERTEX;

typedef VERTEX* pVERTEX;

typedef struct TAG_NODE {
    int index;
    int u;
    int v;
    double w;
    TAG_NODE* next;
} NODE;

typedef NODE* pNODE;

typedef VERTEX ELEMENT;
typedef ELEMENT* pELEMENT;

typedef struct TAG_HEAP {
    int capacity;
    int size;
    pELEMENT* H;
} HEAP;

typedef HEAP* pHEAP;

#endif 
