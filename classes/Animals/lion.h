#ifndef LION_H
#define LION_H

#include "animals.h"
using namespace std;

class Lion: public Animal 
{
    public :

        Lion(){cout << "AcL";}
        Lion(int x, int y, int e):Animal{x,y,e}{cout << "AcL";}
        ~Lion() override {}

        void print() const override;
        char getLettre() const override;

    protected :
    
    private :

};

#endif