#ifndef GAZELLE_H
#define GAZELLE_H

#include "animals.h"
using namespace std;

class Gazelle: public Animal 
{
    public :

        Gazelle(){cout << "AcG";}
        Gazelle(int x, int y, int e):Animal{x,y,e}{cout << "AcG";}
        ~Gazelle() override {}

        void print() const override;
        char getLettre() const override;

    protected :
    
    private :

};

#endif