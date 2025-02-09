//Name: Tariq Alharbi
//ASU ID: 1227159754

#ifndef GRAPH_H
#define GRAPH_H

#include "data_structures.h"

class Graph {
public:
    Graph(int vertices, bool isDirected);
    ~Graph();
    void addEdge(int u, int v, double w, int flag, bool addSymmetric = true);
    void printAdjacencyList() const;
    void dijkstraSingleSource(int source);
    void dijkstraSinglePair(int source, int destination);
    void printPath(int source, int destination) const;
    void printLength(int source, int destination) const;

private:
    int n;
    bool isDirected;
    pVERTEX* vertices;
    pNODE* adjacencyList;

    int mostRecentSource;
    int mostRecentDestination;
    bool singleSourceComputed;

    void initializeSingleSource(int source);
    void relax(pVERTEX u, pVERTEX v, double weight);
};

#endif
