#include "main.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

void processInstructions(Graph& graph) {
    std::string command;
    while (std::cin >> command) {
        if (command == "Stop") {
            break;
        }
        else if (command == "PrintADJ") {
            graph.printAdjacencyList();
        }
        else if (command == "SinglePair") {
            int source, destination;
            std::cin >> source >> destination;
            graph.dijkstraSinglePair(source, destination);
        }
        else if (command == "SingleSource") {
            int source;
            std::cin >> source;
            graph.dijkstraSingleSource(source);
        }
        else if (command == "PrintLength") {
            int s, t;
            std::cin >> s >> t;
            graph.printLength(s, t);
        }
        else if (command == "PrintPath") {
            int s, t;
            std::cin >> s >> t;
            graph.printPath(s, t);
        }
        else {
            std::cerr << "Invalid instruction." << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: ./PJ3 <InputFile> <GraphType> <Flag>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error opening file: " << argv[1] << std::endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m;

    bool isDirected = std::string(argv[2]) == "DirectedGraph";
    int flag;
    try {
        flag = std::stoi(argv[3]);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid flag argument: " << argv[3] << std::endl;
        return 1;
    }
    if (flag != 2 && flag != 1) {
        std::cerr << "Flag argument out of range: " << argv[3] << std::endl;
        return 1;
    }

    Graph graph(n, isDirected);

    for (int i = 0; i < m; ++i) {
        int edgeIndex, u, v;
        double w;
        inputFile >> edgeIndex >> u >> v >> w;
        graph.addEdge(u, v, w, flag);
    }

    inputFile.close();

    processInstructions(graph);

    return 0;
}
