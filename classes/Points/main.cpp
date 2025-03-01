#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    Point p1;
    Point p2 {5, 8};
    p1.print();
    p2.print();
    Point* pp1 {nullptr};
    pp1 = new Point;
    Point *pp3 {new Point {3,5}};
    pp1->print();
    pp3->print();
    Point tab_point[3];
}