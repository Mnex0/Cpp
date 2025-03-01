#include <iostream>

using namespace std;

struct Point{
    int x,y;
};

void affichepoint(Point pt)
{
    cout << pt.x << " " << pt.y << endl;
}
void modifpoint1(Point pt)
{
    int choice;
    cout << "Que voulez-vous modifier ?" << endl;
    cout << "1 - x" << endl;
    cout << "2 - y" << endl;
    cin >> choice;
    while (choice < 1 && choice > 3)
    {
        cout << "Que voulez-vous modifier ?" << endl;
        cout << "1 - x" << endl;
        cout << "2 - y" << endl;
        cin >> choice;
    }
    switch (choice)
    {
    case 1:
        cout << "Entrez l'absisse souhaitée" << endl;
        cin >> pt.x;
        break;
    
    case 2:
        cout << "Entrez l'ordonnée souhaitée" << endl;
        cin >> pt.y;
        break;

    default:
        break;
    }
}

void modifpoint2(Point* pt)
{
    int choice;
    cout << "Que voulez-vous modifier ?" << endl;
    cout << "1 - x" << endl;
    cout << "2 - y" << endl;
    cin >> choice;
    while (choice < 1 && choice > 3)
    {
        cout << "Que voulez-vous modifier ?" << endl;
        cout << "1 - x" << endl;
        cout << "2 - y" << endl;
        cin >> choice;
    }
    switch (choice)
    {
    case 1:
        cout << "Entrez l'absisse souhaitée" << endl;
        cin >> pt->x;
        break;
    
    case 2:
        cout << "Entrez l'ordonnée souhaitée" << endl;
        cin >> pt->y;
        break;

    default:
        break;
    }
}

void modifpoint3(Point& pt)
{
    int choice;
    cout << "Que voulez-vous modifier ?" << endl;
    cout << "1 - x" << endl;
    cout << "2 - y" << endl;
    cin >> choice;
    while (choice < 1 && choice > 3)
    {
        cout << "Que voulez-vous modifier ?" << endl;
        cout << "1 - x" << endl;
        cout << "2 - y" << endl;
        cin >> choice;
    }
    switch (choice)
    {
    case 1:
        cout << "Entrez l'absisse souhaitée" << endl;
        cin >> pt.x;
        break;
    
    case 2:
        cout << "Entrez l'ordonnée souhaitée" << endl;
        cin >> pt.y;
        break;

    default:
        break;
    }
}

int main()
{
    Point po;
    po = {14, 27};
    affichepoint(po);
    modifpoint1(po);
    affichepoint(po);
    modifpoint2(&po);
    affichepoint(po);
    modifpoint3(po);
    affichepoint(po);

    //Point* pts = {{14, 27}, {13, 1}, {5, 8}};
}