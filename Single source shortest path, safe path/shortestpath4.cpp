#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <tuple>

struct Edge;

struct Node {
    int id;
    std::vector<Edge> edges;
};

struct Edge {
    int weight;
    int target;
};

struct Compare {
    bool operator()(const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) {
        return std::get<0>(a) > std::get<0>(b);
    }
};

int dijkstra(int source, int target, int maxNodes, const std::vector<Node>& nodes) {
    std::vector<std::vector<int>> distance(maxNodes + 1, std::vector<int>(nodes.size(), INT_MAX));
    std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, Compare> pq; // {weight, node, steps}
    
    distance[1][source] = 0;
    pq.push(std::tuple(0, source, 1));


    while(!pq.empty()) {
        auto [currNodeDist, currNode, numSteps] = pq.top();
        pq.pop();
        if (currNode == target){
            return currNodeDist;
            
        }
        
        if (numSteps >= maxNodes){
            continue;
        }
            
        for (const Edge& x: nodes[currNode].edges) {
            int edgeTarget = x.target;
            int edgeWeight = x.weight;
            if (distance[numSteps + 1][edgeTarget] > distance[numSteps][currNode] + edgeWeight) {
                distance[numSteps + 1][edgeTarget] = distance[numSteps][currNode] + edgeWeight;
                pq.push(std::tuple(distance[numSteps + 1][edgeTarget], edgeTarget, numSteps+1));
            }
        }
    }

    return -1;
}

int main() {
    int numOfTestCases;
    std::cin >> numOfTestCases;

    for (int i = 0; i < numOfTestCases; i++) {
        int numOfJunctions;
        std::cin >> numOfJunctions;
        std::vector<Node> nodes;
        
        for (int j = 0; j < numOfJunctions; j++) {
            Node tempNode;
            tempNode.id = j;
            nodes.push_back(tempNode);
        }

        for (int j = 0; j < numOfJunctions; j++) {
            std::vector<Edge> tempEdges;
            int numOfEdges;
            std::cin >> numOfEdges;
            
            for (int k = 0; k < numOfEdges; k++) {
                
                int target, edgeWeight;
                std::cin >> target >> edgeWeight;

                Edge tempEdge;
                tempEdge.weight = edgeWeight;
                tempEdge.target = target;
                tempEdges.push_back(tempEdge);
            }

            nodes[j].edges = tempEdges;
        }
        
        int numOfQueries;
        std::cin >> numOfQueries;
        for (int j = 0; j < numOfQueries; j++) {
            int source, target, maxNodesTemp;
            std::cin >> source >> target >> maxNodesTemp;
            int maxNodes = std::min(30, maxNodesTemp);
            std::cout << dijkstra(source, target, maxNodes, nodes)<< std::endl;
        }
    }

    return 0;
}