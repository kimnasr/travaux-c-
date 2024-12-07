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


/*
 
 Pour implémenter l'algorithme de Dijkstra en C++, nous commençons par définir les structures de données nécessaires. L'algorithme est conçu pour trouver le chemin le plus court d'un nœud source à tous les autres nœuds d'un graphe pondéré. Voici une description étape par étape de l'implémentation :
 Structures de données
 Représentation graphique : nous pouvons représenter le graphe à l'aide d'une liste d'adjacence. Chaque nœud aura une liste de paires, où chaque paire se compose d'un nœud voisin et du poids de l'arête qui les relie.
 File d'attente prioritaire : une file d'attente prioritaire (souvent implémentée avec un tas minimal) est utilisée pour récupérer efficacement le nœud suivant avec la plus petite distance provisoire.
 Tableau de distance : un tableau pour suivre la distance la plus courte entre le nœud source et chaque nœud du graphe.
 Ensemble visité : un ensemble pour suivre les nœuds qui ont déjà été traités.
 Étapes d'implémentation
 Initialisation : définissez la distance au nœud source sur 0 et tous les autres nœuds sur l'infini. Insérez le nœud source dans la file d'attente prioritaire.
 Boucle principale : tant que la file d'attente prioritaire n'est pas vide :
 Extraire le nœud avec la plus petite distance.
 Pour chaque voisin de ce nœud, calculer la distance provisoire. Si cette distance est inférieure à la distance actuellement connue, mettre à jour la distance et insérer le voisin dans la file d'attente prioritaire.
 Termination : l'algorithme se termine lorsque tous les nœuds ont été traités et que le tableau de distance contient les chemins les plus courts à partir du nœud source.
 
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
*/

// implementation of BFS in C++
//0 1 2 3 Program ended with exit code: 0

/*
 Techniques de parcours de graphes pour une recherche efficace

 Le parcours de graphes est un aspect fondamental des algorithmes de graphes, permettant une recherche et une récupération de données efficaces. Dans cette section, nous explorerons diverses techniques de parcours, en nous concentrant sur leur mise en œuvre et leurs performances dans différents scénarios.
 Recherche en largeur (BFS)
 
 BFS est une méthode de parcours qui explore tous les sommets au niveau de profondeur actuel avant de passer aux sommets au niveau de profondeur suivant. Cette technique est particulièrement utile pour trouver le chemin le plus court dans les graphes non pondérés. L'algorithme peut être implémenté à l'aide d'une structure de données de file d'attente, qui permet une exploration systématique des nœuds.
 

#include <iostream>
#include <vector>
#include <queue>

void BFS(int start, const std::vector<std::vector<int>>& graph) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        std::cout << node << " ";

        for (int i : graph[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>> graph = {{1, 2}, {0, 3}, {0}, {1}};
    BFS(0, graph);
    return 0;
}
*/
/**
 
 Les techniques BFS et DFS sont toutes deux essentielles pour parcourir les graphes, chacune avec ses forces et ses faiblesses. La BFS est optimale pour trouver le chemin le plus court dans les graphes non pondérés, tandis que la DFS est mieux adaptée pour explorer tous les chemins possibles. La compréhension de ces techniques est essentielle pour mettre en œuvre des algorithmes de recherche efficaces dans diverses applications, notamment l'apprentissage automatique et l'intelligence artificielle.
 
 Recherche en profondeur (DFS)
 DFS est une autre technique de parcours qui explore autant que possible chaque branche avant de revenir en arrière. Cette méthode est utile pour les scénarios où vous devez explorer tous les chemins possibles, comme dans la résolution d'énigmes ou la recherche de chemin dans les labyrinthes.
 
 0 1 3 4 2 Program ended with exit code: 0
 */

#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V; // Number of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists

    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v's list.
}

void Graph::DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i])
            DFSUtil(*i, visited);
    }
}

void Graph::DFS(int v) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(v, visited);
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.DFS(0);
    return 0;
}
