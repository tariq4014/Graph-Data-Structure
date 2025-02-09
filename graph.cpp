//Name: Tariq Alharbi
//ASU ID: 1227159754

#include "graph.h"
#include "heap.h"
#include "stack.h"
#include <cfloat>
#include <iostream>
#include <vector>
#include <iomanip>

Graph::Graph(int vertices, bool isDirected) {
    this->n = vertices;
    this->isDirected = isDirected;
    this->vertices = new pVERTEX[vertices + 1];
    this->adjacencyList = new pNODE[vertices + 1];
    this->mostRecentSource = -1;
    this->mostRecentDestination = -1;
    this->singleSourceComputed = false;

    for (int i = 1; i <= vertices; ++i) {
        this->vertices[i] = new VERTEX();
        this->vertices[i]->index = i;
        this->vertices[i]->color = WHITE;
        this->vertices[i]->key = DBL_MAX;
        this->vertices[i]->pi = -1;
        this->vertices[i]->position = i;
        this->adjacencyList[i] = nullptr;
    }
}

Graph::~Graph() {
    for (int i = 1; i <= n; ++i) {
        delete vertices[i];
        pNODE current = adjacencyList[i];
        while (current != nullptr) {
            pNODE temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] vertices;
    delete[] adjacencyList;
}

void Graph::addEdge(int u, int v, double w, int flag, bool addSymmetric) {

    pNODE newNode = new NODE();
    if (newNode == nullptr) {
        exit(1);
    }

    newNode->index = u;
    newNode->u = u;
    newNode->v = v;
    newNode->w = w;
    newNode->next = nullptr; 

    if (flag == 1) {
        newNode->next = adjacencyList[u];
        adjacencyList[u] = newNode;
    }
    else {
        pNODE* adj = &adjacencyList[u];
        while (*adj != nullptr) {
            adj = &((*adj)->next);
        }
        *adj = newNode;
    }

    if (!isDirected && addSymmetric) {
        addEdge(v, u, w, flag, false); 
    }
}

void Graph::printAdjacencyList() const {
    for (int i = 1; i <= n; ++i) {
        std::cout << "ADJ[" << i << "]:";
        pNODE current = adjacencyList[i];
        while (current != nullptr) {
            std::cout << "-->[" << current->u << " " << current->v << ": "
                << std::fixed << std::setprecision(2) << current->w << "]";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

void Graph::initializeSingleSource(int source) {
    for (int i = 1; i <= n; ++i) {
        vertices[i]->key = DBL_MAX;
        vertices[i]->pi = -1;
        vertices[i]->color = WHITE;
    }
    vertices[source]->key = 0;
}

void Graph::relax(pVERTEX u, pVERTEX v, double weight) {
    if (v->key > u->key + weight) {
        v->key = u->key + weight;
        v->pi = u->index;
    }
}

void Graph::dijkstraSingleSource(int source) {
    initializeSingleSource(source);

    MinHeap minHeap(n);
    for (int i = 1; i <= n; ++i) {
        minHeap.insert(vertices[i]);
    }

    while (!minHeap.isEmpty()) {
        pVERTEX u = minHeap.extractMin();
        u->color = BLACK;
        pNODE current = adjacencyList[u->index];
        while (current != nullptr) {
            pVERTEX v = vertices[current->v];
            if (v->color != BLACK) {
                relax(u, v, current->w);
                minHeap.decreaseKey(v->position, v->key);
            }
            current = current->next;
        }
    }

    mostRecentSource = source;
    mostRecentDestination = -1;
    singleSourceComputed = true;
}

void Graph::dijkstraSinglePair(int source, int destination) {
    dijkstraSingleSource(source);

    if (vertices[destination]->key == DBL_MAX) {
    }
    else {
        mostRecentSource = source;
        mostRecentDestination = destination;
        singleSourceComputed = false;
    }

}

void Graph::printLength(int source, int destination) const {
    if ((singleSourceComputed && source == mostRecentSource) ||
        (!singleSourceComputed && source == mostRecentSource && destination == mostRecentDestination)) {
        if (vertices[destination]->key == DBL_MAX) {
            std::cout << "There is no path from " << source << " to " << destination << "." << std::endl;
        }
        else {
            std::cout << "The length of the shortest path from " << source << " to " << destination << " is: " <<std::setw(8)<< std::fixed << std::setprecision(2) << vertices[destination]->key << std::endl;
        }
    }
    else {
        std::cerr << "Invalid PrintLength instruction." << std::endl;
    }
}

void Graph::printPath(int source, int destination) const {
    if ((singleSourceComputed && source == mostRecentSource) ||
        (!singleSourceComputed && source == mostRecentSource && destination == mostRecentDestination)) {
        if (vertices[destination]->key == DBL_MAX) {
            std::cout << "There is no path from " << source << " to " << destination << "." << std::endl;
        }
        else {
            Stack stack(n);
            pVERTEX v = vertices[destination];
            while (v->pi != -1) {
                stack.push(v);
                v = vertices[v->pi];
            }
            stack.push(vertices[source]);

            std::cout << "The shortest path from " << source << " to " << destination << " is:" << std::endl;
            bool first = true;
            while (!stack.isEmpty()) {
                v = stack.pop();
                if (!first) {
                    std::cout << "-->";
                }
                std::cout << "[" << v->index << ":" << std::setw(8) << std::fixed << std::setprecision(2) << v->key << "]";
                first = false;
            }
            std::cout << "." << std::endl;
        }
    }
    else {
        std::cerr << "Invalid PrintPath instruction." << std::endl;
    }
}

