//
//  main.cpp
//  LectureFichierBinaire
//
//  Created by nasr on 28/11/2024.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // Nom du fichier binaire à lire
    string nomFichier = "fichier_binaire.dat";

    // Ouverture du fichier en mode binaire
    ifstream fichier(nomFichier, ios::binary);
    if (!fichier) {
        cerr << "Erreur : Impossible d'ouvrir le fichier " << nomFichier << endl;
        return 1;
    }

    cout << "Lecture du fichier binaire : " << nomFichier << endl;

    // Se déplacer à la fin pour obtenir la taille du fichier
    fichier.seekg(0, ios::end);
    size_t taille = fichier.tellg();
    fichier.seekg(0, ios::beg);

    // Lire tout le contenu dans un buffer
    vector<char> buffer(taille);
    fichier.read(buffer.data(), taille);

    // Vérification de la lecture
    if (!fichier) {
        cerr << "Erreur lors de la lecture du fichier." << endl;
        return 1;
    }

    fichier.close();

    // Affichage des données lues (octet par octet)
    cout << "Contenu du fichier (en hexadécimal) :" << endl;
    for (size_t i = 0; i < buffer.size(); ++i) {
        // Affichage en format hexadécimal
        cout << hex << (unsigned(buffer[i]) & 0xFF) << " ";
        if ((i + 1) % 16 == 0) cout << endl; // Nouvelle ligne toutes les 16 valeurs
    }
    cout << endl;

    return 0;
}

