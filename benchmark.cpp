#include <string>
#include <chrono>
#include "functions.h"

int main() {
    std::vector<std::string> paths = {"Grafos/grafo_W_1.txt","Grafos/grafo_W_2.txt","Grafos/grafo_W_3.txt"};
    std::vector<int> vertices = {10, 20, 30, 40, 50};
    std::vector<long> durations = {0, 0, 0, 0, 0};
    int startVertex = 1;
    
    std::ofstream shortestPathTimeFile("shortestPathTime.csv", std::ios::app);
    std::ofstream shortestPathStatsFile("shortestPathStats.txt");
    shortestPathTimeFile << "File," << "10," << "20," << "30," << "40," << "50" << std::endl;
    for (unsigned int pathIdx = 0; pathIdx < paths.size(); pathIdx++) {
        Graph graph = createGraphFromFile(paths[pathIdx]);
        std::cout << std::endl;
        std::cout << "Finding Shortest Path on File: " << paths[pathIdx] << std::endl;
        shortestPathStatsFile << std::endl;
        shortestPathStatsFile << "File: " << paths[pathIdx] << std::endl;
        for (unsigned int endVertexIdx = 0; endVertexIdx < vertices.size(); endVertexIdx++) {
            shortestPathStatsFile << std::endl;
            shortestPathStatsFile << "End Vertex:" << vertices[endVertexIdx] << std::endl;
            shortestPathStatsFile << "-----------------------------" << std::endl;
            shortestPathStatsFile << std::endl;

            durations[endVertexIdx] = measureShortestPathTime(graph, startVertex, vertices[endVertexIdx], shortestPathStatsFile);
        }
        shortestPathTimeFile << pathIdx+1 << ","  << durations[0] << "," <<  durations[1] << "," << durations[2] << "," << durations[3] << "," << durations[4] << std::endl;  
        std::cout << "Shortest Path Found." << std::endl;
        std::cout << std::endl;
    }

    shortestPathTimeFile.close();
    shortestPathStatsFile.close();

    std::cout << "---------------------------------------------" << std::endl;

    std::ofstream minimumSpanningTreeFile("minimumSpanningTreeTime.csv");
    std::ofstream shortestMinimumTreeStatsFile("shortestMinimumTreeStats.txt");
    minimumSpanningTreeFile << "Graph 1," << "Graph 2," << "Graph 3" << std::endl;
    for (unsigned int pathIdx = 0; pathIdx < paths.size(); pathIdx++) {
        Graph graph = createGraphFromFile(paths[pathIdx]);
        std::cout << std::endl;
        std::cout << "Finding Minimum Tree of File: " << paths[pathIdx] << std::endl;
        shortestMinimumTreeStatsFile << std::endl;
        shortestMinimumTreeStatsFile << "File: " << paths[pathIdx] << std::endl;

        long duration = measureMinimumSpanningTreeTime(graph, shortestMinimumTreeStatsFile);

        if (pathIdx != paths.size()-1)
            minimumSpanningTreeFile << duration << ",";
        else {
            minimumSpanningTreeFile << duration << std::endl;
        }

        std::cout << "Minimum Spanning Tree Found." << std::endl;
        std::cout << std::endl;
    }

    minimumSpanningTreeFile.close();
    shortestMinimumTreeStatsFile.close();

    std::cout << "---------------------------------------------" << std::endl;

    std::ofstream eccentricityTimeFile("eccentricityTime.csv", std::ios::app);
    std::ofstream eccentricityStatsFile("eccentricityStats.txt");
    eccentricityTimeFile << "File," << "10," << "20," << "30," << "40," << "50" << std::endl;
    for (unsigned int pathIdx = 0; pathIdx < paths.size(); pathIdx++) {
        Graph graph = createGraphFromFile(paths[pathIdx]);
        std::cout << std::endl;
        std::cout << "Finding Shortest Path on File: " << paths[pathIdx] << std::endl;
        eccentricityStatsFile << std::endl;
        eccentricityStatsFile << "File: " << paths[pathIdx] << std::endl;
        for (unsigned int vertexIdx = 0; vertexIdx < vertices.size(); vertexIdx++) {
            shortestPathStatsFile << std::endl;
            shortestPathStatsFile << "Vertex:" << vertices[vertexIdx] << std::endl;
            shortestPathStatsFile << "-----------------------------" << std::endl;
            shortestPathStatsFile << std::endl;

            durations[vertexIdx] = measureEccentricityTime(graph, vertices[vertexIdx], eccentricityStatsFile);
        }
        eccentricityTimeFile << pathIdx+1 << ","  << durations[0] << "," <<  durations[1] << "," << durations[2] << "," << durations[3] << "," << durations[4] << std::endl;  
        std::cout << "Eccentricity Found." << std::endl;
    }

    eccentricityTimeFile.close();
    eccentricityStatsFile.close();

    return 0;
}