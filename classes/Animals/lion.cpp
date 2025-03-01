#include "lion.h"
using namespace std;

void Lion::print() const 
{
    cout << "This animal has " << this->getE() << " energy and the coordinates : x = " << this->getX() << ", y = " << this->getY() << endl;
}

char Lion::getLettre() const
{
    return 'L';
}