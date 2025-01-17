//
//  main.cpp
//  heritage
//
//  Created by nasr on 11/09/2024.
//


//--------Programme sur utilisation des fonctions membres en ligne (IMG-1712 )
//--------Passage d'argument d'adresse d objet à une fonction membre
// Programme affiche
/*
 a et b:0ou0
 b et c:1ou1
 Program ended with exit code: 0
*/


//------------------
#include <iostream>
using namespace std;


class point
{
public:
    
    
    point (int abs=0,int ord=0):x(abs),y(ord) {}
    bool coincide (point *);
    
    //point(): x(0),y(0) {}  //constructeur 1 (sans arguments)
    //point(int abs):x(abs),y(abs){} ;  //constructeur 2 (un argument)
    //point(int abs,int ord):x(abs),y(ord) {};       //constructeur 3 (deux arguments)
    //void affiche(string="");       // fct affiche1 (sans argument)
    //void affiche (string);// fct affiche2 (un argument chaine)
    
private:
    int x,y;
};

//point::point():x(0),y(0){}                     //constructeur 1
//point::point (int abs):x(abs),y(abs) {}        //constructeur 2
//point::point (int abs,int ord):x(abs),y(ord){} //constructeur3
/*
void point::affiche ()     //fonction affiche1
{
    cout << "je suis en:" <<x<<" "<<y<<endl;
}
*/
/*
void point::affiche(string message) //fonction affiche2
{
    cout << message << "Je suis en:"<<x<<" "<<y<<endl;
}
*/


/*
template <typename T> int compte (T * tab,int n)
{
    int nz=0;
    for (int i=0;i<n;i++) if(!tab[i]) nz++;
    return nz;
}


class vect
{
public:
    
    vect(int abs=0,int ord=0) : x(abs), y(ord){}
    void affiche ()
    {
        cout << x <<""<<y;
    }
        friend int operator < (vect,vect);
        //cout << " mes coordonees sont : " <<x<<" "<<y<<endl;
    
    
private:
    int x,y;
};

int operator < (vect a,vect b)
{ return a.x*a.x + a.y*a.y < b.x*b.x+ b.y*b.y;
}




class point
{
public:
    
    point(int abs=0,int ord=0) : x(abs), y(ord){}
    void affiche () const
    {
        cout << "Je suis un point \n";
        cout << " mes coordonees sont : " <<x<<" "<<y<<endl;
    }
    
protected:
    int x,y;
};

class pointcol: public point
{
    public:
    pointcol (int abs=0,int ord=0,short c1=1):point(abs,ord),couleur(c1){}
    void affiche() const
    {
        cout << "Je suis un point colore \n";
        cout << "mes coordonnees sont:"<<x<<""<<y;
        cout << " et ma couleur est:  "<< couleur<<endl;
    }
    
    //void colore (short c1){couleur=c1;}
    private:
    short couleur;
};
*/


bool point::coincide (point * adpt)
{
    //return((pt.x==x)&&(pt.y==y));
    return((adpt->x ==x) && (adpt->y==y));
}

int main() {
    // insert code here...
    
    //pointcol p;
    //p.initialise(10,20);p.colore(5);
    //p.affiche();
    //p.deplace(2, 4);
    //p.affiche();
    
    //std::cout << "Hello, World!\n";
    //return 0;
    
    //point p(3,5); point *adp =&p;
    //pointcol pc (8,6,2);pointcol * adpc = &pc;
    //adp->affiche();adpc->affiche();
    //cout << "-------------------\n";
    //adp=adpc;
    //adp->affiche(); adpc->affiche();
    
    //vect u(3,2),v(4,1),w;
    //w=min(u,v);
    
    //int n=4,p=12;
    //float x=2.5,y=3.25;
    
    //w=min(u,v);
    //cout << "min (u,v)="; w.affiche();  //int min(int,int)
    //cout << "min (x,y)=" << minimum (x,y) << endl;  //float min(float,float)
    
    /*
    int t[5]={5,2,0,2,0};
    char c[6]={0,12,0,0,0,5};
    cout << "compte (t) = " <<compte (t,5)<< "\n";
    cout << "compte (C) = " <<compte (c,6)<< "\n";
    */
     
    point a,b(1),c(1,0);
    cout<< "a et b:"<<a.coincide(&b)<<"ou"<<b.coincide(&a)<<endl;
    cout<<"b et c:"<<b.coincide(&c)<<"ou"<<c.coincide(&b)<<endl;
    //a.affiche();
    //point b(5);
    
    //b.affiche("Point b -");
    //point c (3,12);
    
    //c.affiche("Hello -------");
}


