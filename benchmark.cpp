#include <string>
#include <chrono>
#include "functions.h"

int main() {
    std::vector<std::string> paths = {"Grafos/grafo_W_1.txt","Grafos/grafo_W_2.txt","Grafos/grafo_W_3.txt"};
    std::vector<int> vertices = {10, 20, 30, 40, 50};
    std::vector<long> durations = {0, 0, 0, 0, 0};
    int startVertex = 1;
    std::ofstream shortestPathTimeFile("shortestPathTime.csv", std::ios::app);


    shortestPathTimeFile << "Arquivo," << "10," << "20," << "30," << "40," << "50" << std::endl;
    for (unsigned int pathIdx = 0; pathIdx < paths.size(); pathIdx++) {
        std::cout << std::endl;
        Graph graph = createGraphFromFile(paths[pathIdx]);
        std::cout << std::endl;
        std::cout << "File: " << paths[pathIdx] << std::endl;
        for (unsigned int endVertexIdx = 0; endVertexIdx < vertices.size(); endVertexIdx++) {
            std::cout << std::endl;
            std::cout << "End Vertex:" << vertices[endVertexIdx] << std::endl;
            std::cout << "-----------------------------" << std::endl;
            std::cout << std::endl;

            durations[endVertexIdx] = measureShortestPathTime(graph, startVertex, vertices[endVertexIdx]);
        }
        shortestPathTimeFile << pathIdx+1 << ","  << durations[0] << "," <<  durations[1] << "," << durations[2] << "," << durations[3] << "," << durations[4] << std::endl;  
    }

    shortestPathTimeFile.close();
    return 0;
}