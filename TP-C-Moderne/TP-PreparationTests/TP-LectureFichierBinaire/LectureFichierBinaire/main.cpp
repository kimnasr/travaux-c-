//
//  main.cpp
//  LectureFichierBinaire
//
//  Created by nasr on 28/11/2024.
//

/*
 Explication du code :

     1.    Ouverture du fichier :
     •    Utilisation de ifstream pour ouvrir un fichier en mode lecture binaire (ios::binary).
     •    Vérifie si le fichier s’est bien ouvert en testant if (!fichier).
     2.    Obtenir la taille du fichier :
     •    Avec seekg et tellg, le curseur du fichier est déplacé pour calculer la taille du fichier.
     3.    Lecture des données :
     •    Les données sont stockées dans un tampon (un std::vector<char>) pour faciliter leur gestion.
     •    read lit les octets du fichier dans ce tampon.
     4.    Affichage du contenu :
     •    Les octets sont affichés en format hexadécimal pour une meilleure lisibilité.
     •    Une nouvelle ligne est insérée après 16 octets pour un format lisible.

 Exemple de fichier binaire :

 Supposons que vous avez un fichier binaire nommé fichier_binaire.dat contenant les octets suivants :

 0x41 0x42 0x43 0x44 0x45 0x46 0x47 0x48 0x49 0x4A 0x4B 0x4C 0x4D 0x4E 0x4F 0x50

 Le programme affichera :

 Lecture du fichier binaire : fichier_binaire.dat
 Contenu du fichier (en hexadécimal) :
 41 42 43 44 45 46 47 48 49 4A 4B 4C 4D 4E 4F 50

 Points à noter :

     1.    Fichiers binaires réels : Cette méthode est générique et peut être utilisée pour des fichiers binaires comme des images, des exécutables, ou tout autre fichier non-textuel.
     2.    Adaptation : Si le fichier contient des structures spécifiques (ex. entiers, flottants), vous pouvez adapter le code pour interpréter les données correctement.

 */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    // Nom du fichier binaire à lire
    string nomFichier = "/Users/nasr/Documents/Personnel/formation/objet C++/aout024/TP C++/TP-n2/TP-n3/TP constructeur/Thread/LectureFichierBinaire/LectureFichierBinaire/fichier_binaire.dat";

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

