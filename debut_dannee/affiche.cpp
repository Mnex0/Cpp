#include <iostream>
using namespace std;

void affiche(int param = 0)
{
    cout << param << endl;
}

void affiche2(int parametre[3])
{
    for (int i = 0; i < 3; ++i)
    {
        cout << parametre[i] << endl;
    }
}

void affiche3(int* tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << tab[i] << endl;
    }
}

int main()
{
    int a;
    cout << "Entrez un nombre" << endl;
    cin >> a;
    affiche(a);


    int b[3] = {1, 2, 3};
    affiche2(b);


    int size;
    cout << "Entrez une taille de tableau" << endl;
    cin >> size;

    int* c = new int[size];
    for (int j = 0; j < size; j++)
        c[j] = j+1;
    affiche3(c, size);
    delete[] c;


    return 0;
}