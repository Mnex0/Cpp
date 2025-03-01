#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

#define MaxE 50

class Animal 
{
    public:

        //---------------------Constructeurs

        Animal();
        Animal(int x, int y, int e);

        //-----------------------Destructeur

        virtual ~Animal();

        //----------------------------Geters

        int getX() const {return x;}
        int getY() const {return y;}
        int getE() const {return e;}

        void setX(int x) {this->x = x;}
        void setY(int y) {this->y = y;}
        void setE(int e) {this->e = e;}

        virtual void print() const;
        virtual char getLettre() const;
    
    private:
        int x;
        int y;
        int e;
};

#endif