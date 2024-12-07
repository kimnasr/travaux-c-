//
//  main.cpp
//  SearchAlgo
//
//  Created by nasr on 07/12/2024.
//  extracted from https://www.restack.io/p/search-algorithm-optimization-answer-fastest-search-algorithm-cpp-cat-ai
//  affiche 0 1 2 3 4 Program ended with exit code: 0
/*
 #include <iostream>
 #include <list>
 #include <queue>
 using namespace std;
 
 class Graph {
 int V; // Number of vertices
 list<int> *adj; // Pointer to an array containing adjacency lists
 
 public:
 Graph(int V);
 void addEdge(int v, int w);
 void BFS(int s);
 };
 
 Graph::Graph(int V) {
 this->V = V;
 adj = new list<int>[V];
 }
 
 void Graph::addEdge(int v, int w) {
 adj[v].push_back(w); // Add w to v's list.
 }
 
 void Graph::BFS(int s) {
 bool *visited = new bool[V];
 for (int i = 0; i < V; i++)
 visited[i] = false;
 
 queue<int> q;
 visited[s] = true;
 q.push(s);
 
 while (!q.empty()) {
 s = q.front();
 cout << s << " ";
 q.pop();
 
 for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
 if (!visited[*i]) {
 visited[*i] = true;
 q.push(*i);
 }
 }
 }
 }
 
 int main() {
 Graph g(5);
 g.addEdge(0, 1);
 g.addEdge(0, 2);
 g.addEdge(1, 3);
 g.addEdge(1, 4);
 g.BFS(0);
 return 0;
 }
 */

/**
 
 To implement Dijkstra's algorithm in C++, we start by defining the necessary data structures. The algorithm is designed to find the shortest path from a source node to all other nodes in a weighted graph. Here’s a step-by-step breakdown of the implementation:

 Data Structures
 Graph Representation: We can represent the graph using an adjacency list. Each node will have a list of pairs, where each pair consists of a neighboring node and the weight of the edge connecting them.
 Priority Queue: A priority queue (often implemented with a min-heap) is used to efficiently retrieve the next node with the smallest tentative distance.
 Distance Array: An array to keep track of the shortest distance from the source node to each node in the graph.
 Visited Set: A set to keep track of nodes that have already been processed.
 Implementation Steps
 Initialization: Set the distance to the source node to 0 and all other nodes to infinity. Insert the source node into the priority queue.
 Main Loop: While the priority queue is not empty:
 Extract the node with the smallest distance.
 For each neighbor of this node, calculate the tentative distance. If this distance is less than the currently known distance, update the distance and insert the neighbor into the priority queue.
 Termination: The algorithm terminates when all nodes have been processed, and the distance array contains the shortest paths from the source node.
 output
 Distance from node 0 to node 0 is 0
 Distance from node 0 to node 1 is 3
 Distance from node 0 to node 2 is 1
 Distance from node 0 to node 3 is 5
 Program ended with exit code: 0
 */



#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

void dijkstra(int source, const vector<vector<pair<int, int>>> & graph) {
    vector<int> distance(graph.size(), numeric_limits<int>::max());
    distance[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distance[node]) continue;

        for (const auto& neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            if (distance[node] + weight < distance[nextNode]) {
                distance[nextNode] = distance[node] + weight;
                pq.push({distance[nextNode], nextNode});
            }
        }
    }

    // Output the shortest distances
    for (int i = 0; i < distance.size(); ++i) {
        cout << "Distance from node " << source << " to node " << i << " is " << distance[i] << endl;
    }
}

int main() {
    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {2, 1}},
        {{0, 4}, {2, 2}, {3, 2}},
        {{0, 1}, {1, 2}, {3, 5}},
        {{1, 2}, {2, 5}}
    };
    dijkstra(0, graph);
    return 0;
}
 
 
