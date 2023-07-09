#include "classes.h"

Edge::Edge(int vertexA, int vertexB, float weight) 
    : vertexA(vertexA), vertexB(vertexB), weight(weight) {}

int Edge::getVertexA() const {
    return vertexA;
}

int Edge::getVertexB() const {
    return vertexB;
}

float Edge::getWeight() const {
    return weight;
}

bool Edge::operator>(const Edge& other) const {
    return weight > other.weight;
}

Graph::Graph(int numVertices) : numVertices(numVertices), adjacencyList(numVertices) {}

void Graph::addEdge(int vertexA, int vertexB, float weight){
    Edge edge(vertexA, vertexB, weight);
    adjacencyList[vertexA].push_back(edge);
    adjacencyList[vertexB].push_back(edge);
}

std::pair<std::vector<float>, std::vector<int>> Graph::dijkstraShortestPath(int startVertex){
    // Vector of Distances with numVertices size and inf value on each position
    // inf value means no info on the actual distances yet
    std::vector<float> distance(numVertices, std::numeric_limits<float>::infinity());

    // Vector to store previous Vertex on the shortest path to each Vertex
    std::vector<int> previousVertex(numVertices, numVertices);
    distance[startVertex] = 0;

    // Store pair of weight, numVertex with smallest weight on top
    std::priority_queue<std::pair<float, int>, std::vector<std::pair<float, int>>, std::greater<std::pair<float, int>>> pq;
    pq.push({0, startVertex});

    while (!pq.empty()){
        // Info of vertex with smallest weight
        float currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        // If currentDistance > distance[currentVertex]
        // Shorter path found, no need to recalculate
        if (currentDistance > distance[currentVertex])
            continue;

        // On the currentVertex, for each edge:
        // Find which way to walk on the edge
        // Add the edge weight to find distance to the vertex on the other end
        // If distance is shorter than shortest old one, push to the queue
        for (auto &edge : adjacencyList[currentVertex]){
            int adjacentVertex = edge.getVertexA();
            if (currentVertex == edge.getVertexA())
                adjacentVertex = edge.getVertexB();
            float weight = edge.getWeight();
            float newDistance = currentDistance + weight;

            if (newDistance < distance[adjacentVertex]){
                distance[adjacentVertex] = newDistance;
                previousVertex[adjacentVertex] = currentVertex;
                pq.push({newDistance, adjacentVertex});
            }
        }
    }
    return {distance, previousVertex};
}

std::vector<int> Graph::getPath(int startVertex, int endVertex, std::vector<float> distance, std::vector<int> previousVertex){
    std::vector<int> path;
    int currentVertex = endVertex;

    // If distance to vertex == inf, no path available.
    if (distance[endVertex] == std::numeric_limits<float>::infinity())
        return path;

    // Run through the path backwards to find path
    while (currentVertex != startVertex){
        path.push_back(currentVertex);
        currentVertex = previousVertex[currentVertex];
    }
    path.push_back(startVertex);
    std::reverse(path.begin(), path.end());

    return path;
}

std::pair<float, std::vector<int>> Graph::pathVertex2Vertex(int startVertex, int endVertex){
    std::pair<std::vector<float>, std::vector<int>> startVertexInfo = dijkstraShortestPath(startVertex);
    float distance = startVertexInfo.first[endVertex];
    std::vector<int> path = getPath(startVertex, endVertex, startVertexInfo.first, startVertexInfo.second);

    return {distance, path};
}

std::vector<Edge> Graph::minimumSpanningTree(){
    // Vector to store tree
    std::vector<Edge> minimumTree;
    // Vector to store visited vertices
    std::vector<bool> checked(numVertices, false);
    // Store smallest edge value on top
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;

    // Starting from Vertex 0
    // Insert its edges on queue
    checked[0] = true;
    for (auto &edge : adjacencyList[0]){
        pq.push(edge);
    }

    while (!pq.empty()){
        // Always the smallest edge on top
        Edge currentEdge = pq.top();
        // Remove edge from queue
        pq.pop();

        // Get its vertices
        int vertexA = currentEdge.getVertexA();
        int vertexB = currentEdge.getVertexB();

        // Store the vertex that hasn't been visited yet
        // If both vertices have been visited, do nothing (Cycles not created)
        if (checked[vertexA] && !checked[vertexB]){
            minimumTree.push_back(currentEdge);
            checked[vertexB] = true;
            for (const auto &edge : adjacencyList[vertexB]){
                pq.push(edge);
            }
        }
        else if (!checked[vertexA] && checked[vertexB]){
            minimumTree.push_back(currentEdge);
            checked[vertexA] = true;
            for (auto &edge : adjacencyList[vertexA]){
                pq.push(edge);
            }
        }
    }
    return minimumTree;
}

float Graph::getMinimumSpanningTreeWeight(std::vector<Edge> minimumTree) {
    float weight = 0.0;
    for (auto &edge : minimumTree)
        weight += edge.getWeight();
    return weight;
}

float Graph::getEccentricity(int startVertex) {
    // Find all distances then return max distance
    std::vector<float> distances = dijkstraShortestPath(startVertex).first;
    auto maxIt = std::max_element(distances.begin(), distances.end());
    if (maxIt != distances.end())
        return *maxIt;
    return std::numeric_limits<float>::lowest();
}

void Graph::printGraph() {
    std::cout << "Num of Vertices: " << numVertices << std::endl;
    std::cout << "Edges: " << std::endl;

    for (int i = 0; i < numVertices; i++) {
        for (auto &edge : adjacencyList[i]) {
            std::cout << "Vertex A: " << edge.getVertexA() + 1 << ", Vertex B: " << edge.getVertexB() + 1 << ", Weight: " << edge.getWeight() << std::endl;
        }
    }
}