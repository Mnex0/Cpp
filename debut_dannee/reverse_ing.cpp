#include <iostream>
using namespace std;

int main()
{
    int t[3];
    int i, j;
    int* p_t = NULL;//  <----- Mauvaise pratique réglée, il fallait définir le pointeur comme un pointeur nul

    for (i = 0, j = 0; i < 3; i++)
    {
        t[i] = j++ + i;//       <------ t = [0, 2, 4] stock les multiples de deux
    }
    for (i = 0; i < 3; i++)
    {
        cout << t[i] << " ";//     <------ affiche les multiples de deux
        cout << "\n";
    }
    for (i = 0; i < 3; i++)
    {
        cout << *(t+i) << " ";//     <------ affiche les multiples de deux par déréférencement
        cout << "\n";
    }
    for (p_t = t+2; p_t >= t; p_t--)
    {
        cout << *p_t << " ";//     <------ affiche les multiples de deux en décroissance
        cout << "\n";
    }
}