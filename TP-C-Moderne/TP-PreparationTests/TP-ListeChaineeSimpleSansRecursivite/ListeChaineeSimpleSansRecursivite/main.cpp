//
//  main.cpp
//  ListeChaineeSimpleSansRecursivite
//
//  Created by nasr on 28/11/2024.
//
/*
 Explications du code :
 
 1.    Structure Node :
 •    Chaque nœud contient une donnée data et un pointeur next vers le nœud suivant.
 2.    Fonction reverseList :
 •    Utilise trois pointeurs :
 •    prev : le nœud précédent.
 •    current : le nœud actuel à traiter.
 •    next : le nœud suivant pour sauvegarder la progression.
 •    Parcourt la liste en inversant les liens entre les nœuds.
 3.    Affichage de la liste :
 •    printList parcourt les nœuds et affiche leurs données.
 4.    Libération de la mémoire :
 •    Nettoie les nœuds après leur utilisation pour éviter les fuites de mémoire.
 
 Exemple d’exécution :
 
 Liste originale : 1 2 3 4 5
 Liste inversée : 5 4 3 2 1
 */

#include <iostream>

// Définition d'un nœud de la liste chaînée
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Fonction pour inverser une liste chaînée
Node* reverseList(Node* head) {
    Node* prev = nullptr; // Pointeur pour suivre le nœud précédent
    Node* current = head; // Pointeur pour suivre le nœud actuel
    Node* next = nullptr; // Pointeur pour suivre le nœud suivant

    while (current != nullptr) {
        next = current->next; // Sauvegarder le nœud suivant
        current->next = prev; // Inverser le lien
        prev = current;       // Avancer le pointeur `prev`
        current = next;       // Avancer le pointeur `current`
    }

    return prev; // `prev` devient le nouveau tête de la liste inversée
}

// Fonction pour afficher une liste chaînée
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Programme principal
int main() {
    // Création d'une liste chaînée simple : 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Liste originale : ";
    printList(head);

    // Inverser la liste
    head = reverseList(head);

    std::cout << "Liste inversée : ";
    printList(head);

    // Libération de la mémoire
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

