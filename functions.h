#include <fstream>
#include <chrono>
#include "classes.h"

Graph createGraphFromFile(std::string& filename);
void printShortestPathStats(std::pair<float, std::vector<int>>& path);
long measureShortestPathTime(Graph& graph, int startVertex, int endVertex);