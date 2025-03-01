#include <iostream>
#include "animals.h"
using namespace std;

/*-------------------------------------------- Constructor -------------------------------------------- */

//Constructeurs
Point::Point()
{
    x = 0;
    y = 0;
    cout << "Call on default contructor" << endl;
}

Point::Point(int init_x, int init_y)
{
    x = init_x;      //Constructeur additionnel
    y = init_y;
}

void Point::print()
{
    cout << "This dot has the coordinates : x = " << this->x << " et y = " << this->y << endl;
}