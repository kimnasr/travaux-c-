//
//  main.cpp
//  ArbreRechercheBinaire
//
//  Created by nasr on 28/11/2024.
//
/*
Explications :

    1.    Structure Node :
    •    Représente un nœud de l’arbre contenant :
    •    data : la valeur.
    •    left : le pointeur vers le sous-arbre gauche.
    •    right : le pointeur vers le sous-arbre droit.
    2.    Classe BinarySearchTree :
    •    Contient les fonctions pour manipuler l’arbre :
    •    insert : pour insérer une nouvelle valeur.
    •    search : pour rechercher une valeur.
    •    remove : pour supprimer une valeur.
    •    inOrder : pour afficher l’arbre en ordre croissant (parcours in-order).
    3.    Fonctionnement des principales méthodes :
    •    Insertion :
    •    Place une valeur à sa position correcte (à gauche si elle est plus petite, à droite sinon).
    •    Recherche :
    •    Parcourt l’arbre en suivant les branches gauche/droite en fonction de la valeur recherchée.
    •    Suppression :
    •    Cas 1 : Le nœud est une feuille → Supprime directement.
    •    Cas 2 : Le nœud a un enfant → Remplace le nœud par cet enfant.
    •    Cas 3 : Le nœud a deux enfants → Remplace par le plus petit nœud du sous-arbre droit (successeur).
    4.    Parcours en ordre (in-order traversal) :
    •    Parcourt le sous-arbre gauche, affiche la valeur, puis parcourt le sous-arbre droit.

 Parcours en ordre (in-order traversal) : 20 30 40 50 60 70 80
 40 trouvé dans l'arbre.
 Arbre après suppression de 30 : 20 40 50 60 70 80
 Program ended with exit code: 0
 
Exemple d’exécution :

Entrée :

Insérer : 50, 30, 70, 20, 40, 60, 80
Rechercher : 40
Supprimer : 30

Sortie :

Parcours en ordre (in-order traversal) : 20 30 40 50 60 70 80
40 trouvé dans l'arbre.
Arbre après suppression de 30 : 20 40 50 60 70 80
*/


#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    // Fonction pour insérer un élément dans l'arbre
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    // Fonction pour rechercher un élément dans l'arbre
    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    bool search(int value) {
        return search(root, value);
    }

    // Fonction pour trouver le nœud avec la valeur minimale
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Fonction pour supprimer un nœud de l'arbre
    Node* remove(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            // Cas où le nœud a au plus un enfant
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Cas où le nœud a deux enfants
            Node* temp = findMin(node->right); // Trouver le successeur
            node->data = temp->data;          // Remplacer la valeur
            node->right = remove(node->right, temp->data); // Supprimer le successeur
        }

        return node;
    }

    void remove(int value) {
        root = remove(root, value);
    }

    // Parcours en ordre (in-order traversal)
    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void inOrder() {
        inOrder(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insérer des valeurs dans l'arbre
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Parcours en ordre (in-order traversal) : ";
    bst.inOrder();

    // Rechercher une valeur
    int key = 40;
    if (bst.search(key)) {
        std::cout << key << " trouvé dans l'arbre.\n";
    } else {
        std::cout << key << " non trouvé dans l'arbre.\n";
    }

    // Supprimer une valeur
    bst.remove(30);
    std::cout << "Arbre après suppression de 30 : ";
    bst.inOrder();

    return 0;
}
