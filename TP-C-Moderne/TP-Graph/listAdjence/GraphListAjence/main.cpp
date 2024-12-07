//
//  main.cpp
//  GraphListAjence
//
//  Created by nasr on 07/12/2024.
//
/*
sortie
0 —> 1
1 —> 2
2 —> 1 —> 0
3 —> 2
4 —> 5
5 —> 4
Program ended with exit code: 0
*/

#include <iostream>
using namespace std;
 
// Structure de données pour stocker les nœuds de la liste d'adjacence
struct Node
{
    int val;
    Node* next;
};
 
// Structure de données pour stocker une arête de graphe
struct Edge {
    int src, dest;
};
 
class Graph
{
    // Fonction pour allouer un nouveau nœud pour la liste d'adjacence
    Node* getAdjListNode(int dest, Node* head)
    {
        Node* newNode = new Node;
        newNode->val = dest;
 
        // pointe le nouveau nœud vers la tête actuelle
        newNode->next = head;
 
        return newNode;
    }
 
    int N;    // nombre total de nœuds dans le graphe
 
public:
 
    // Un array de pointeurs vers Node pour représenter le
    // liste de contiguïté
    Node **head;
 
    // Constructeur
    Graph(Edge edges[], int n, int N)
    {
        // alloue de la mémoire
        head = new Node*[N]();
        this->N = N;
 
        // initialise le pointeur principal pour tous les sommets
        for (int i = 0; i < N; i++) {
            head[i] = nullptr;
        }
 
        // ajoute des arêtes au graphe orienté
        for (unsigned i = 0; i < n; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
 
            // insère au début
            Node* newNode = getAdjListNode(dest, head[src]);
 
            // pointe le pointeur principal vers le nouveau nœud
            head[src] = newNode;
 
            // décommentez le code suivant pour le graphe non orienté
 
            /*
            newNode = getAdjListNode(src, head[dest]);
 
            // change le pointeur principal pour pointer vers le nouveau nœud
            head[dest] = newNode;
            */
        }
    }
 
    // Destructeur
    ~Graph() {
        for (int i = 0; i < N; i++) {
            delete[] head[i];
        }
 
        delete[] head;
    }
};
 
// Fonction pour imprimer tous les sommets voisins d'un sommet donné
void printList(Node* ptr)
{
    while (ptr != nullptr)
    {
        cout << " —> " << ptr->val;
        ptr = ptr->next;
    }
    cout << endl;
}
 
// Implémentation de graphe en C++ sans utiliser STL
int main()
{
    // un array d'arêtes de graphe selon le diagramme ci-dessus
    Edge edges[] =
    {
        // la paire {x, y} représente une arête de `x` à `y`
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };
 
    // nombre total de nœuds dans le graphe (étiquetés de 0 à 5)
    int N = 6;
 
    // calcule le nombre total d'arêtes
    int n = sizeof(edges)/sizeof(edges[0]);
 
    // construit le graphe
    Graph graph(edges, n, N);
 
    // affiche la représentation de la liste d'adjacence d'un graphe
    for (int i = 0; i < N; i++)
    {
        // affiche le sommet donné
        cout << i;
 
        // imprime tous ses sommets voisins
        printList(graph.head[i]);
    }
 
    return 0;
}
