//
//  main.cpp
//  hashTableExemple
//
//  Created by nasr on 28/11/2024.
//
// http://tvaira.free.fr/bts-sn/poo-c++/cours-poo-c++/cours-c++-conteneurs.pdf -p16
//Affiche
//Adresse IP de www.google.fr : 216.58.204.67

//La table :
//www.google.fr -> 216.58.204.67
//www.cplusplus.com -> 167.114.170.15
//Program ended with exit code: 0
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// g++ unordered-map.cpp -std=c++0x
// g++ >= 4.8
// g++ unordered-map.cpp -std=c++11
int main() {
    
unordered_map<string, string> hashtable;

unordered_map<string, string> ::iterator it;
    
    //hashtable.emplace("www.wikipedia.fr", "78.109.84.114");
    //cout << "Adresse IP : " << hashtable["www.wikipedia.fr"] << endl;
    
    //unordered_map<Key,T>::iterator it;
    //(*it).first;             // the key value (of type Key)
    //(*it).second;            // the mapped value (of type T)
    //(*it);                   // the "element value" (of type pair<const Key,T>)

    //(*it).first.insert(1," <#const Tp &t#>");
    (*it).second.insert(1,"167.114.170.15");
    //(*it).second ="167.114.170.15"";
    
hashtable.insert(make_pair("www.cplusplus.com", "167.114.170.15"));
hashtable.insert(make_pair("www.google.fr", "216.58.204.67"));

cout << "Adresse IP de www.google.fr : " << hashtable["www.google.fr"] << endl << endl;
cout << "La table : " << endl;

for (auto itr = hashtable.begin(); itr != hashtable.end(); itr++) {
    cout << (*itr).first << " -> " << (*itr).second << endl;
}
    
return 0; }
