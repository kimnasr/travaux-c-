//
//  main.cpp
//  MatrixAdjence
//
//  Created by nasr on 07/12/2024.
//

// C++ Program to Implement Adjacency Matrix
/*
Output
Adjacency Matrix:
0 0 0 1 1 0
0 0 1 0 1 1
0 1 0 1 0 1
1 0 1 0 0 1
1 1 0 0 0 1
0 1 1 1 1 0
Program ended with exit code: 0
 
 
 Define the number of vertices V in the graph
 Create a 2D array adjMatrix of size V x V.
 Initialize all elements of adjMatrix to 0.
 Define a function addEdge(u, v) to add an edge between two vertices:
 Check if u and v are valid vertices (0 <= u, v < V).
 If valid, set adjMatrix[u][v] = 1
 Also set adjMatrix[v][u] = 1 as this is an undirected graph.
 Define a function printAdjMatrix() to print the adjacency matrix.
 Iterate through the matrix using two for loops and print the value of the cells.
 
 To represent the above undirected graph , the adjacency matrix should look like:

 The row and columns number represents the vertex of the graph in the adjacency matrix.
 Cell having value =1 indicates there is an edge between the row and column vertex in the graph.
 
*/

/*
#include <iostream>
using namespace std;
// Number of vertices
#define V 6

// Function to initialize the adjacency matrix
void initAdjMatrix(int adjMatrix[V][V])
{
    // Initialize all elements of the adjacency matrix to 0
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(int adjMatrix[V][V], int u, int v)
{
    // Mark the edge between vertices u and v as 1
    adjMatrix[u][v] = 1;
    // For undirected graph, mark opposite edge as well
    adjMatrix[v][u] = 1;
}

// Function to print the adjacency matrix
void printAdjMatrix(int adjMatrix[V][V])
{
    // Print the adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int adjMatrix[V][V];

    // Initialize the adjacency matrix
    initAdjMatrix(adjMatrix);

    // Add edges to the graph
    addEdge(adjMatrix, 0, 3);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 1, 5);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 2, 5);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 5);
    addEdge(adjMatrix, 4, 5);

    cout << "Adjacency Matrix:" << endl;
    // Print the adjacency matrix
    printAdjMatrix(adjMatrix);

    return 0;
}
*/

/*
 
 
 0 1 0 0 1
 1 0 1 1 1
 0 1 0 1 0
 0 1 1 0 1
 1 1 0 1 0
 Program ended with exit code: 0
 */

/*
#include <iostream>
#include <vector>

void addEdge(std::vector<std::vector<int>>& adjMatrix, int u, int v, int weight = 1) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight; // For undirected graphs
}

void printMatrix(const std::vector<std::vector<int>>& adjMatrix) {
    for (const auto& row : adjMatrix) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int numVertices = 5;
    std::vector<std::vector<int>> adjMatrix(numVertices, std::vector<int>(numVertices, 0));

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 4);
    addEdge(adjMatrix, 1, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 3);
    addEdge(adjMatrix, 3, 4);

    printMatrix(adjMatrix);

    return 0;
}
*/

/**
 Advanced Example with Weighted Graphs

 For weighted graphs, you can specify the weight of each edge.
 0 10 0 0 20
 10 0 30 40 50
 0 30 0 60 0
 0 40 60 0 70
 20 50 0 70 0
 Program ended with exit code: 0
 
 bool hasEdge(const std::vector<std::vector<int>>& adjMatrix, int u, int v) {
     return adjMatrix[u][v] != 0;
 }
 
 void iterateEdges(const std::vector<std::vector<int>>& adjMatrix) {
     int numVertices = adjMatrix.size();
     for (int i = 0; i < numVertices; ++i) {
         for (int j = 0; j < numVertices; ++j) {
             if (adjMatrix[i][j] != 0) {
                 std::cout << "Edge between " << i << " and " << j << " with weight " << adjMatrix[i][j] << std::endl;
             }
         }
     }
 }
 
 What is an adjacency matrix in C++?

 An adjacency matrix is a 2D array used to represent a graph, where each element indicates whether a pair of vertices is adjacent.

 How do you create an adjacency matrix in C++?

 You create an adjacency matrix by defining a 2D array or a vector of vectors and initializing it to represent the graph.

 What are the advantages of using an adjacency matrix?

 Adjacency matrices provide fast edge addition, removal, and check operations, and are simple to implement for dense graphs.

 What are the disadvantages of using an adjacency matrix?

 They consume a lot of memory for large, sparse graphs due to their O(V^2) space complexity.

 How do you handle weighted edges in an adjacency matrix?

 For weighted graphs, store the weight of the edge as the value in the matrix instead of 1.
 
 */

#include <iostream>
#include <vector>

void addEdge(std::vector<std::vector<int>>& adjMatrix, int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight; // For undirected graphs
}

void printMatrix(const std::vector<std::vector<int>>& adjMatrix) {
    for (const auto& row : adjMatrix) {
        for (const auto& val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int numVertices = 5;
    std::vector<std::vector<int>> adjMatrix(numVertices, std::vector<int>(numVertices, 0));

    addEdge(adjMatrix, 0, 1, 10);
    addEdge(adjMatrix, 0, 4, 20);
    addEdge(adjMatrix, 1, 2, 30);
    addEdge(adjMatrix, 1, 3, 40);
    addEdge(adjMatrix, 1, 4, 50);
    addEdge(adjMatrix, 2, 3, 60);
    addEdge(adjMatrix, 3, 4, 70);

    printMatrix(adjMatrix);

    return 0;
}
