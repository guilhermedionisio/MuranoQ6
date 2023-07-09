#include <vector>
#include <list>
#include <queue>
#include <limits>
#include <iostream>
#include <algorithm>

class Edge {
    int vertexA;
    int vertexB;
    float weight;

    public:
        Edge(int vertexA, int vertexB, float weight);

        int getVertexA() const;
        int getVertexB() const;
        float getWeight() const;
        bool operator>(const Edge& other) const;
};

class Graph {
    int numVertices;
    std::vector<std::list<Edge>> adjacencyList;
    public:
        Graph(int numVertices);

        void addEdge(int vertexA, int vertexB, float weight);
        std::pair<std::vector<float>, std::vector<int>> dijkstraShortestPath(int startVertex);
        std::vector<int> getPath(int startVertex, int endVertex, std::vector<float> distance, std::vector<int> previousVertex);
        std::pair<float, std::vector<int>> pathVertex2Vertex(int startVertex, int endVertex);
        std::vector<Edge> minimumSpanningTree();
        float getMinimumSpanningTreeWeight(std::vector<Edge> minimumTree);
        float getEccentricity(int startVertex);
        void printGraph();
};