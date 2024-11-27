//
//  main.cpp
//  AffichageDoublonsDunTableau
//
//  Created by nasr on 27/11/2024.
//

//Nombres en double dans le tableau : 6 5 4
//Program ended with exit code: 0

/*
Explications du programme :

    1.    Structure de données :
    •    La table de hachage (std::unordered_map) est utilisée pour compter les occurrences des éléments. Elle stocke les paires clé-valeur où la clé est un nombre du tableau et la valeur est le nombre d’occurrences de cet élément.
    2.    Comptage des occurrences :
    •    Pour chaque élément du tableau, la valeur associée à la clé dans la table de hachage est incrémentée :

countMap[num]++;


    3.    Détection des doublons :
    •    Une fois le comptage terminé, les clés dont la valeur est supérieure à 1 représentent les nombres en double.
    4.    Affichage des résultats :
    •    Les doublons sont affichés. Si aucun nombre n’est trouvé avec une fréquence supérieure à 1, le programme indique qu’il n’y a pas de doublons.

 Complexité :

     •    Temps :  O(n)
     •    Le programme parcourt le tableau une fois pour compter les occurrences, puis parcourt la table de hachage pour trouver les doublons.
     •    Espace :  O(n)
     •    La table de hachage stocke les fréquences pour chaque élément unique.

 Amélioration possible :

 Si le tableau est très grand et que l’espace est limité, une solution triée peut être envisagée (avec complexité  O(n \log n) ).
 
*/

#include <iostream>
#include <unordered_map> // Pour la table de hachage
#include <vector>        // Pour le tableau dynamique

void findDuplicates(const std::vector<int>& arr) {
    std::unordered_map<int, int> countMap; // Table de hachage pour stocker les fréquences

    // Parcourir le tableau pour compter les occurrences de chaque élément
    for (int num : arr) {
        countMap[num]++;
    }

    // Afficher les nombres en double
    std::cout << "Nombres en double dans le tableau : ";
    bool found = false;
    for (const auto& pair : countMap) {
        if (pair.second > 1) { // Si un élément apparaît plus d'une fois
            std::cout << pair.first << " ";
            found = true;
        }
    }

    if (!found) {
        std::cout << "Aucun doublon trouvé.";
    }

    std::cout << std::endl;
}

int main() {
    // Exemple de tableau avec plusieurs doublons
    std::vector<int> arr = {4, 5, 6, 7, 4, 8, 6, 9, 5, 10};

    // Trouver et afficher les nombres en double
    findDuplicates(arr);

    return 0;
}

