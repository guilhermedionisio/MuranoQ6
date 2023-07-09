#include "functions.h"

Graph createGraphFromFile(std::string& fileName) {
    std::ifstream file(fileName);

    int numVertices;
    file >> numVertices;
    Graph graph(numVertices);

    int vertexA, vertexB;
    float weight;
    while (file >> vertexA >> vertexB >> weight) {
        graph.addEdge(vertexA - 1, vertexB - 1, weight);
    }

    return graph;
}

void printShortestPathStats(std::pair<float, std::vector<int>>& stats) {
    if (stats.second.empty()) {
        std::cout << "Non Existent Path." << std::endl;
    } else {
        std::cout << "Distance: " << stats.first << std::endl;
        std::cout << "Shortest Path: ";
        for (auto it = stats.second.begin(); it != stats.second.end(); it++) {
            std::cout << *it + 1;
            if (it != std::prev(stats.second.end()))
                std::cout << " -> ";
        }
        std::cout << std::endl;
    }
}

long measureShortestPathTime(Graph& graph, int startVertex, int endVertex) {
    auto start = std::chrono::high_resolution_clock::now();
    std::pair<float, std::vector<int>> stats = graph.pathVertex2Vertex(startVertex-1, endVertex-1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    printShortestPathStats(stats);
    
    return duration.count();
}