#include "gazelle.h"
using namespace std;

void Gazelle::print() const
{
    cout << "This animal has " << this->getE() << " energy and the coordinates : x = " << this->getX() << ", y = " << this->getY() << endl;
}

char Gazelle::getLettre() const
{
    return 'L';
}