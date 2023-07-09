#include <fstream>
#include <chrono>
#include "classes.h"

Graph createGraphFromFile(std::string& filename);

void printShortestPathStats(std::pair<float, std::vector<int>>& path, std::ofstream& shortestPathStatsFile);
long measureShortestPathTime(Graph& graph, int startVertex, int endVertex, std::ofstream& shortestPathStatsFile);

void printMinimumSpanningTreeStats(float minimumTreeWeight, std::vector<Edge>& minimumTree, std::ofstream& shortestMinimumTreeStatsFile);
long measureMinimumSpanningTreeTime(Graph graph, std::ofstream& shortestMinimumTreeStatsFile);

void printEccentricityStats(float stats, std::ofstream& eccentricityStatsFile);
long measureEccentricityTime(Graph graph, int startVertex, std::ofstream& eccentricityStatsFile);
