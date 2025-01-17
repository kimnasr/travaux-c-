#include <iostream>
#include "revision0.h"
#include <stdlib.h>
#include <cstring>


int menu1(){
    cout << "1- ajouter une Ecole\n";
    cout << "2- afficher les Ecoles\n";
    cout << "3- ajouter un etudiant dans une Ecole\n";
    cout << "4- lister les etudiants d'une Ecole\n";
    cout << "5- afficher les etudiants par ordre croissant dans une ecole\n";
    cout << "6- aller au menu classe\n";
    cout << "7- Quitter\n";
    int a;
    cin >> a;
    return a;
}

int menu2(){
    cout << "1- ajouter une classe\n";
    cout << "2- afficher les classes\n";
    cout << "3- ajouter un etudiant dans une classe\n";
    cout << "4- lister les etudiants d'une classe\n";
    cout << "5- afficher les classes par ordre croissant\n";
    cout << "6- Quitter\n";
    int a;
    cin >> a;
    return a;
}


ECOLE saisirEcole(int a){
    ECOLE b;
    b.id = a+1;
    cout <<endl <<"saisissez le libelle de l'école" << endl;
    cin >> b.libelle;
    //cin.ignore();
    //getline(cin, b.libelle);
    cout <<endl <<"quel est l'effectif de l'école" << endl;
    cin >> b.effectif;

    cout <<endl <<endl <<"id :" <<b.id <<endl <<"libelle :" <<b.libelle <<endl <<"effectif :" <<b.effectif <<endl;

    return b;
}


CLASSE saisirClasse(int a){
    CLASSE b;
    b.id = a+1;
    cout <<endl <<"saisissez le libelle de la classe" << endl;
    cin >> b.libelle;
    //cin.ignore();
    //getline(cin, b.libelle);
    cout <<endl <<"quel est l'effectif de la classe?" << endl;
    cin >> b.effectif;

    cout <<endl <<endl <<"id :" <<b.id <<endl <<"libelle :" <<b.libelle <<endl <<"effectif :" <<b.effectif <<endl;

    return b;
}


int ajouterClasse(CLASSE tabClass[], int nbrClass, CLASSE b){
    //cout << nbrClass;
    tabClass[nbrClass].id = b.id;
    tabClass[nbrClass].effectif = b.effectif;
    tabClass[nbrClass].libelle = b.libelle;


    nbrClass++;
    cout << nbrClass;
    return nbrClass;
}


int ajouterEcole(ECOLE tabEcole[], int nbrEcole, ECOLE b){
    //cout << nbrClass;
    tabEcole[nbrEcole].id = b.id;
    tabEcole[nbrEcole].effectif = b.effectif;
    tabEcole[nbrEcole].libelle = b.libelle;

    nbrEcole++;
    cout << nbrEcole;
    return nbrEcole;
}



void afficheTabClasse(CLASSE tabClass[], int nbrClass){

    for(int i(0); i<nbrClass; i++)
       {
          cout <<endl <<"Nom classe: " <<tabClass[i].libelle <<endl;
          cout <<"Classe id: " << tabClass[i].id << endl;
          cout <<"Effectif: " << tabClass[i].effectif << endl <<endl;
       }
}


void afficheTabEcole(ECOLE tabEcole[], int nbrEcole){

    for(int i(0); i<nbrEcole; i++)
       {
          cout <<endl <<"Nom ECOLE: " <<tabEcole[i].libelle <<endl;
          cout <<"ECOLE id: " << tabEcole[i].id << endl;
          cout <<"Effectif: " << tabEcole[i].effectif << endl <<endl;
       }
}


int controleClasse(string a, CLASSE tabClass[], int nbrClass){
    for(int i(0); i<nbrClass; i++){
        if(a == tabClass[i].libelle){
            //return 0;
            return 1;
        }
    }
    return 0;
}


int controleEcole(string a, ECOLE tabEcole[], int nbrEcole){
    for(int i(0); i<nbrEcole; i++){
        if(a == tabEcole[i].libelle){
            //return 0;
            return 1;
        }
    }
    return 0;
}


CLASSE getClasseByName(string a, CLASSE tabClass[], int nbrClass){
    for(int i(0); i<nbrClass; i++){
        if(a == tabClass[i].libelle){
            return tabClass[i];
        }
    }
    return tabClass[0];
}


ECOLE getEcoleByName(string a, ECOLE tabEcole[], int nbrEcole){
    for(int i(0); i<nbrEcole; i++){
        if(a == tabEcole[i].libelle){
            return tabEcole[i];
        }
    }
    return tabEcole[0];
}



ETUDIANT saisirEtudiant(int a, CLASSE tabClass[], int nbrClass){
    ETUDIANT b;
    string classVoulu=" ";
    b.id = a+1;
    cout <<endl <<"saisissez le nom de l'etudiant svp" << endl;
    cin >> b.nom;
    cout <<endl <<"saisissez le prenom de l'etudiant svp" << endl;
    cin >> b.prenom;
    cout <<endl <<"saisissez l'age de l'etudiant svp" << endl;
    cin >> b.age;
    cout <<endl <<"saisissez l'école de l'étudiant" << endl;
    cin >> b.c2.ECOLE::libelle;
    
    
    do{
        cout << endl <<"Dans quelle classe existante voulez vous ajouter "<<b.prenom <<" "<<b.nom<<"?";
        cin >> classVoulu;
    }while(controleClasse(classVoulu, tabClass, nbrClass)!=1);
    b.cl = getClasseByName(classVoulu, tabClass, nbrClass);


    cout <<endl <<endl <<"id :" <<tabClass->id <<endl <<"libelle :" <<tabClass->libelle <<endl <<"effectif :" <<tabClass->effectif <<endl;

    return b;
}


int ajouterEtudiant(ETUDIANT tabEtu[], int nbrEtu, ETUDIANT b){
    tabEtu[nbrEtu].id = b.id;
    tabEtu[nbrEtu].nom = b.nom;
    tabEtu[nbrEtu].prenom = b.prenom;
    tabEtu[nbrEtu].age = b.age;
    tabEtu[nbrEtu].cl = b.cl;
    tabEtu[nbrEtu].c2 = b.c2;

    nbrEtu++;
    return nbrEtu;
}

/*
int ajouterEcole(ECOLE tabEcole[], int nbrEcole, ECOLE b){
    tabEcole[nbrEcole].id = b.id;
    tabEcole[nbrEcole].libelle = b.libelle;
    tabEcole[nbrEcole].effectif = b.effectif;
    
    nbrEcole++;
    return nbrEcole;
}
*/


void afficherEtudiantParClasse(ETUDIANT tabEtu[], int nbrEtu, CLASSE tabClass[], int nbrClass){
    string a;
    cout << "Quel est le nom de la classe existante dont vous souhaitez voir les etudiants?" <<endl;
    cin >> a;
    cout <<endl <<endl;

    if(controleClasse(a, tabClass, nbrClass)==1){

        for(int i(0); i<nbrEtu; i++){
            if(a == tabEtu[i].cl.libelle){
                cout <<endl <<"Id Etudiant: " <<tabEtu[i].id ;
                cout <<endl <<"Nom Etudiant: " <<tabEtu[i].nom ;
                cout <<endl <<"Prenom Etudiant: " <<tabEtu[i].prenom;
                cout <<endl <<"Age Etudiant: " <<tabEtu[i].age ;
                cout <<endl <<"Classe Etudiant: " <<tabEtu[i].cl.libelle <<endl <<endl;
                cout <<endl <<"Ecole Etudiant: " <<tabEtu[i].c2.libelle <<endl <<endl;
                
            }
        }
    }
    else{
        cout <<"le nom de classe saisi n'existe pas " <<endl;
    }
}


void afficherEtudiantParEcole(ETUDIANT tabEtu[], int nbrEtu, ECOLE tabEcole[], int nbrEcole){
    string a;
    cout << "Quel est le nom de l ecole existante dont vous souhaitez voir les etudiants?" <<endl;
    cin >> a;
    cout <<endl <<endl;

    if(controleEcole(a, tabEcole, nbrEcole)==1){

        for(int i(0); i<nbrEtu; i++){
            if(a == tabEtu[i].c2.libelle){
                cout <<endl <<"Id Etudiant: " <<tabEtu[i].id ;
                cout <<endl <<"Nom Etudiant: " <<tabEtu[i].nom ;
                cout <<endl <<"Prenom Etudiant: " <<tabEtu[i].prenom;
                cout <<endl <<"Age Etudiant: " <<tabEtu[i].age ;
                cout <<endl <<"Classe Etudiant: " <<tabEtu[i].cl.libelle <<endl <<endl;
                cout <<endl <<"Ecole Etudiant: " <<tabEtu[i].c2.libelle <<endl <<endl;
                
            }
        }
    }
    else{
        cout <<"le nom de l ecole saisi n'existe pas " <<endl;
    }
}


void afficheClasseCroissant(CLASSE tabClass[], int nbrClass){
    CLASSE svg;
    for(int i(0); i<(nbrClass-1); i++){
        for(int j(0); j<(nbrClass-1); j++){
            if(tabClass[j].effectif > tabClass[j+1].effectif){
                svg = tabClass[j];
                tabClass[j]=tabClass[j+1];
                tabClass[j+1]=svg;
            }
        }
    }

    afficheTabClasse(tabClass, nbrClass);

}

void afficheEcoleCroissant(ECOLE tabEcole[], int nbrEcole){
    ECOLE svg;
    for(int i(0); i<(nbrEcole-1); i++){
        for(int j(0); j<(nbrEcole-1); j++){
            if(tabEcole[j].effectif > tabEcole[j+1].effectif){
                svg = tabEcole[j];
                tabEcole[j]=tabEcole[j+1];
                tabEcole[j+1]=svg;
            }
        }
    }

    afficheTabEcole(tabEcole, nbrEcole);

}

