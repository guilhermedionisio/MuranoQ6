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

void printShortestPathStats(std::pair<float, std::vector<int>>& stats, std::ofstream& shortestPathStatsFile) {
    if (stats.second.empty()) {
        shortestPathStatsFile << "Non Existent Path." << std::endl;
    } else {
        shortestPathStatsFile << "Distance: " << stats.first << std::endl;
        shortestPathStatsFile << "Shortest Path: ";
        for (auto it = stats.second.begin(); it != stats.second.end(); it++) {
            // +1 because vertices index starts at 1
            // while vector index starts at 0
            shortestPathStatsFile << *it + 1;
            if (it != std::prev(stats.second.end()))
                shortestPathStatsFile << " -> ";
        }
        shortestPathStatsFile << std::endl;
    }
}

long measureShortestPathTime(Graph& graph, int startVertex, int endVertex, std::ofstream& shortestPathStatsFile) {
    auto start = std::chrono::high_resolution_clock::now();
    std::pair<float, std::vector<int>> stats = graph.pathVertex2Vertex(startVertex-1, endVertex-1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    printShortestPathStats(stats, shortestPathStatsFile);
    
    return duration.count();
}

void printMinimumSpanningTreeStats(float minimumTreeWeight, std::vector<Edge>& minimumTree, std::ofstream& shortestMinimumTreeStatsFile) {
    shortestMinimumTreeStatsFile << "Weight: " << minimumTreeWeight << std::endl;
    // Size of Tree = Number of Edges + 1
    shortestMinimumTreeStatsFile << "Number of Vertices on the Tree: " << minimumTree.size() + 1 << std::endl;
}

long measureMinimumSpanningTreeTime(Graph graph, std::ofstream& shortestMinimumTreeStatsFile) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Edge> minimumTree = graph.minimumSpanningTree();
    float minimumTreeWeight = graph.getMinimumSpanningTreeWeight(minimumTree);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    printMinimumSpanningTreeStats(minimumTreeWeight, minimumTree, shortestMinimumTreeStatsFile);

    return duration.count();
}

void printEccentricityStats(float stats, std::ofstream& eccentricityStatsFile) {
    eccentricityStatsFile << "Eccentricity: " << stats << std::endl;
    eccentricityStatsFile << std::endl;
}

long measureEccentricityTime(Graph graph, int startVertex, std::ofstream& eccentricityStatsFile) {
    auto start = std::chrono::high_resolution_clock::now();
    float stats = graph.getEccentricity(startVertex-1);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    printEccentricityStats(stats, eccentricityStatsFile);
    
    return duration.count();
}