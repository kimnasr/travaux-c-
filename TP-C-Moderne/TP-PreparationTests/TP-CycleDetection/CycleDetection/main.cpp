//
//  main.cpp
//  CycleDetection
//
//  Created by nasr on 27/11/2024.
//
//Cycle détecté au nœud avec la valeur : 3
//Program ended with exit code: 0
/*

 
 Pour détecter si une liste chaînée contient un cycle et, si oui, trouver le nœud initial du cycle, on utilise l’algorithme de Floyd, dit “tortue et lièvre” (Floyd’s Cycle Detection Algorithm). Cet algorithme est efficace car il a une complexité temporelle de O(n) et ne nécessite pas de mémoire supplémentaire (complexité spatiale O(1)).

Principe de l’algorithme

    1.    Détection du cycle :
    •    Utilisez deux pointeurs : un pointeur lent (slow, ou “tortue”) et un pointeur rapide (fast, ou “lièvre”).
    •    Le pointeur lent avance d’un pas à la fois.
    •    Le pointeur rapide avance de deux pas à la fois.
    •    Si les deux pointeurs se rencontrent, un cycle existe.
    2.    Trouver le nœud initial du cycle :
    •    Une fois le cycle détecté, réinitialisez l’un des pointeurs (par exemple, slow) au début de la liste, tout en laissant l’autre pointeur (fast) là où il se trouvait.
    •    Déplacez les deux pointeurs à la même vitesse (un pas à la fois).
    •    Le nœud où ils se rencontrent est le début du cycle.
 
 Explications du programme

 1. Structure ListNode

 Chaque nœud de la liste chaînée contient une valeur entière (value) et un pointeur vers le nœud suivant (next).

 2. Détection du cycle

 La boucle while dans la fonction detectCycle avance les pointeurs slow et fast. S’ils se rencontrent, cela signifie qu’un cycle existe.

 3. Trouver le début du cycle

 Après la détection du cycle :
     •    Réinitialisez le pointeur slow au début de la liste.
     •    Déplacez slow et fast à la même vitesse (un pas à la fois).
     •    Le point où ils se rencontrent à nouveau est le début du cycle.

 Exemple d’exécution

 Supposons la liste suivante :

 1 -> 2 -> 3 -> 4 -> 5
           ↑         ↓
           ← ← ← ← ← ←

     •    Le cycle commence au nœud ayant la valeur 3.
     •    La sortie du programme sera :

 Cycle détecté au nœud avec la valeur : 3

 Complexité

     •    Temps :  O(n)
     •    Les deux pointeurs parcourent la liste au maximum deux fois.
     •    Espace :  O(1)
     •    Aucune structure de données supplémentaire n’est utilisée.

 Points importants

     1.    Si la liste est vide ou ne contient qu’un seul nœud, il ne peut pas y avoir de cycle.
     2.    Cet algorithme est optimal pour détecter des cycles et trouver leur point de départ sans utiliser d’espace supplémentaire.
 
*/


#include <iostream>

struct ListNode {
    int value;
    ListNode* next;

    ListNode(int val) : value(val), next(nullptr) {}
};

// Fonction pour détecter si un cycle existe et retourner le nœud initial du cycle
ListNode* detectCycle(ListNode* head) {
    if (!head || !head->next) {
        return nullptr; // Pas de cycle si la liste est vide ou contient un seul nœud
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Étape 1 : Détecter un cycle en utilisant deux pointeurs
    while (fast && fast->next) {
        slow = slow->next;         // Tortue avance d'un pas
        fast = fast->next->next;   // Lièvre avance de deux pas

        if (slow == fast) {        // Les pointeurs se rencontrent
            // Étape 2 : Trouver le nœud initial du cycle
            slow = head;           // Réinitialiser 'slow' au début
            while (slow != fast) { // Avancer les deux pointeurs à la même vitesse
                slow = slow->next;
                fast = fast->next;
            }
            return slow;           // Le nœud de rencontre est le début du cycle
        }
    }

    return nullptr; // Pas de cycle
}

int main() {
    // Exemple : Créer une liste chaînée avec un cycle
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Créer un cycle : le dernier nœud pointe vers le nœud 3
    head->next->next->next->next->next = head->next->next;

    // Vérifier s'il y a un cycle et trouver le nœud initial
    ListNode* cycleNode = detectCycle(head);

    if (cycleNode) {
        std::cout << "Cycle détecté au nœud avec la valeur : " << cycleNode->value << std::endl;
    } else {
        std::cout << "Aucun cycle détecté." << std::endl;
    }

    // (Note : Les nœuds ne sont pas libérés dans cet exemple pour éviter de casser le cycle)
    return 0;
}

