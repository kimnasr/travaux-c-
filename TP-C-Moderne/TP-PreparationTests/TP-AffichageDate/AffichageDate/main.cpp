//
//  main.cpp
//  AffichageDate
//
//  Created by nasr on 27/11/2024.
//
// Affiche Date actuelle : 27/11/24
//Program ended with exit code: 0


#include <iostream>
#include <ctime> // Pour manipuler les fonctions de temps

int main() {
    // Obtenir l'heure actuelle du système
    std::time_t t = std::time(nullptr);

    // Convertir en structure tm pour accéder aux composants de la date
    std::tm* now = std::localtime(&t);

    // Afficher la date au format jj/mm/aa
    std::cout << "Date actuelle : ";
    std::cout << (now->tm_mday < 10 ? "0" : "") << now->tm_mday << "/"
              << (now->tm_mon + 1 < 10 ? "0" : "") << (now->tm_mon + 1) << "/"
              << (now->tm_year + 1900) % 100 << std::endl;

    return 0;
}

/*
Explications du code

    1.    Récupérer l’heure actuelle :

std::time_t t = std::time(nullptr);

    •    std::time(nullptr) renvoie l’heure actuelle en secondes depuis le 1er janvier 1970 (l’époque Unix).

    2.    Convertir en structure tm :

std::tm* now = std::localtime(&t);

    •    std::localtime(&t) transforme l’heure en une structure tm contenant des informations détaillées comme le jour, le mois et l’année.

    3.    Afficher les composants de la date :
    •    now->tm_mday : le jour du mois (1-31).
    •    now->tm_mon : le mois (de 0 à 11, donc on ajoute 1 pour avoir 1-12).
    •    now->tm_year : l’année depuis 1900 (on ajoute 1900 pour avoir l’année actuelle).
    •    Pour obtenir les deux derniers chiffres de l’année : (now->tm_year + 1900) % 100.
    4.    Formatage avec les zéros :
    •    (now->tm_mday < 10 ? "0" : "") ajoute un zéro pour garantir deux chiffres.

Exemple de sortie

Si la date actuelle est le 27 novembre 2024, l’exécution du programme affichera :

Date actuelle : 27/11/24
*/
