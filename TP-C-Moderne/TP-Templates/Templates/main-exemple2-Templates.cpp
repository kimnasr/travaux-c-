//
//  main.cpp
//  Templates
///Users/nasr/Documents/PremierProjet/Travaux C++/TP-C-Moderne/Templates/main.cpp
//  Created by nasr on 26/11/2024.
//
//affiche
/*
 Sommet de la pile : 20
 Sommet après dépilement : 10
 Sommet de la pile : C++
 Program ended with exit code: 0
*/


#include <iostream>
#include <vector>

template <typename T>
class Pile {
private:
    std::vector<T> elements;

public:
    void empiler(T element) {
        elements.push_back(element);
    }

    void depiler() {
        if (elements.empty()) {
            std::cout << "La pile est vide !" << std::endl;
            return;
        }
        elements.pop_back();
    }

    T sommet() const {
        if (elements.empty()) {
            throw std::out_of_range("La pile est vide !");
        }
        return elements.back();
    }

    bool estVide() const {
        return elements.empty();
    }
};

int main() {
    // Pile d'entiers
    Pile<int> pileEntiers;
    pileEntiers.empiler(10);
    pileEntiers.empiler(20);
    std::cout << "Sommet de la pile : " << pileEntiers.sommet() << std::endl;
    pileEntiers.depiler();
    std::cout << "Sommet après dépilement : " << pileEntiers.sommet() << std::endl;

    // Pile de chaînes de caractères
    Pile<std::string> pileStrings;
    pileStrings.empiler("Bonjour");
    pileStrings.empiler("C++");
    std::cout << "Sommet de la pile : " << pileStrings.sommet() << std::endl;

    return 0;
}
