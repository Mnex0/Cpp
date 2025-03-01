#include <iostream>
using namespace std;

class Point 
{
    public:
        //Constructeurs
        Point();
        Point(int x, int y);
        //Destructeur
        ~Point() {cout << "Call on destructor" << endl;};
        //Geters
        int getX() {return x;}
        int getY() {return y;}
        void setX(int x) {this->x = x;}
        void setY(int y) {this->y = y;}
        void print();
    
    private:
        int x;
        int y;    
};