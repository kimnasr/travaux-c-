//
//  main.cpp
//  AlgorithmTriParFusion
//
//  Created by nasr on 28/11/2024.
//
/*
Affiche
Tableau avant le tri : 38 27 43 3 9 82 10
Tableau après le tri : 3 9 10 27 38 43 82
Program ended with exit code: 0
 
 Explication du code :

     1.    fusion :
     •    Fusionne deux sous-tableaux triés en un seul tableau trié.
     •    Utilise deux tableaux temporaires pour éviter d’écraser les données pendant la fusion.
     2.    triFusion :
     •    Divise le tableau principal en deux parties, jusqu’à atteindre un tableau de taille 1.
     •    Fusionne les sous-tableaux triés récursivement.
     3.    Complexité :
     •    Temps : O(n \log n), car le tableau est divisé en deux à chaque appel récursif et la fusion prend O(n).
     •    Espace : O(n), pour les tableaux temporaires utilisés pendant la fusion.

*/

#include <iostream>
#include <vector>
using namespace std;

// Fonction pour fusionner deux sous-tableaux triés
void fusion(vector<int>& tableau, int debut, int milieu, int fin) {
    int n1 = milieu - debut + 1; // Taille du premier sous-tableau
    int n2 = fin - milieu;      // Taille du deuxième sous-tableau

    // Créer des tableaux temporaires
    vector<int> gauche(n1), droite(n2);

    // Copier les données dans les tableaux temporaires
    for (int i = 0; i < n1; i++)
        gauche[i] = tableau[debut + i];
    for (int j = 0; j < n2; j++)
        droite[j] = tableau[milieu + 1 + j];

    // Fusionner les deux sous-tableaux
    int i = 0, j = 0, k = debut;

    while (i < n1 && j < n2) {
        if (gauche[i] <= droite[j]) {
            tableau[k] = gauche[i];
            i++;
        } else {
            tableau[k] = droite[j];
            j++;
        }
        k++;
    }

    // Copier les éléments restants de gauche, s'il y en a
    while (i < n1) {
        tableau[k] = gauche[i];
        i++;
        k++;
    }

    // Copier les éléments restants de droite, s'il y en a
    while (j < n2) {
        tableau[k] = droite[j];
        j++;
        k++;
    }
}

// Fonction récursive pour diviser et trier les sous-tableaux
void triFusion(vector<int>& tableau, int debut, int fin) {
    if (debut < fin) {
        int milieu = debut + (fin - debut) / 2;

        // Diviser en deux sous-tableaux
        triFusion(tableau, debut, milieu);
        triFusion(tableau, milieu + 1, fin);

        // Fusionner les sous-tableaux triés
        fusion(tableau, debut, milieu, fin);
    }
}

// Fonction principale pour tester le tri par fusion
int main() {
    vector<int> tableau = {38, 27, 43, 3, 9, 82, 10};

    cout << "Tableau avant le tri : ";
    for (int val : tableau)
        cout << val << " ";
    cout << endl;

    triFusion(tableau, 0, tableau.size() - 1);

    cout << "Tableau après le tri : ";
    for (int val : tableau)
        cout << val << " ";
    cout << endl;

    return 0;
}

