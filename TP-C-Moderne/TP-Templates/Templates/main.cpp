//
//  main.cpp
//  Templates
//
//  Created by nasr on 26/11/2024.
//
//affiche
/*
Le maximum entre 10 et 20 est : 20
Le maximum entre 5.5 et 2.3 est : 5.5
Le maximum entre Pomme et Banane est : Pomme
Program ended with exit code: -1
*/

#include <iostream>
#include <string>

// Définition d'un template de fonction
template <typename T>
T trouverMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Test avec des entiers
    int int1 = 10, int2 = 20;
    std::cout << "Le maximum entre " << int1 << " et " << int2 << " est : "
              << trouverMax(int1, int2) << std::endl;

    // Test avec des flottants
    double double1 = 5.5, double2 = 2.3;
    std::cout << "Le maximum entre " << double1 << " et " << double2 << " est : "
              << trouverMax(double1, double2) << std::endl;

    // Test avec des chaînes de caractères
    std::string str1 = "Pomme", str2 = "Banane";
    std::cout << "Le maximum entre " << str1 << " et " << str2 << " est : "
              << trouverMax(str1, str2) << std::endl;

    return 0;
}

