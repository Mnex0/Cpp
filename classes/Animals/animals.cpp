#include "animals.h"
using namespace std;

//------------------------------Constructors

Animal::Animal()
{
    x = 0;
    y = 0;
    e = 100;
    cout << "Ac " << endl;
}

Animal::Animal(int x, int y, int e)
{
    this->x = x;
    this->y = y;
    this->e = e;
}

Animal::~Animal()
{
    cout << "Ad ";
}

void Animal::print() const
{
    cout << "This animal has " << this->e << " energy and the coordinates : x = " << this->x << ", y = " << this->y << endl;
}

char Animal::getLettre() const
{
    return 'A';
}