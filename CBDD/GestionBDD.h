#include <stdlib.h>
#include <iostream>
#include <vector>

class ElementBDD
{
    ElementBDD();
    ElementBDD(char* nom, int quantite);
    ~ElementBDD();

    char* getNom() const {return nom;};
    int getQuantite() const {return quantite;}
}

class GestionBDD
{
    GestionBDD();
    GestionBDD(vector<ElementBDD> elem);
    ~GestionBDD();

    void listerArticles() const;
}