#include "animals.h"
#include "monde.h"
using namespace std;

Monde::Monde(int nb_animaux)
{
    this->nb_animaux = nb_animaux;
}

Monde::~Monde()
{
    cout << "Wd ";
}

void Monde::peuplement()
{
    cout << endl;
    if (nb_animaux > kMax_x*kMax_y)
    {
        cout << "Le monde ne peut pas contenir " << nb_animaux << ", sa taille est trop petite" << endl;
        exit;
    }
    else
    {
        for(int i = 0; i < nb_animaux; ++i)
        {
            int x = rand() % kMax_x;
            int y = rand() % kMax_y;
            int e = /*rand() %*/ MaxE;
            while (tab2D[y][x] == 'A')
                {
                    x = rand() % kMax_x;
                    y = rand() % kMax_y;
                }
            tab_anim.push_back(new Animal(x, y, e));
            tab2D[y][x] = 'A';
        }
    }
}

void Monde::affiche() const
{
    cout << endl;
    for(const Animal* elmt : tab_anim)
    {
        elmt->print();
    }
}

void Monde::show() const
{
    cout << endl << '+';
    for (int k = 0; k < kMax_x; ++k)
    {
        cout << '-';
    }
    cout << "+" << endl;
    for (int j = 0; j < kMax_y; ++j)
    {
        cout << '|';
        for (int i = 0; i < kMax_x; ++i)
        {
            if (!tab2D[j][i])
            {
                cout << ' ';
            }
            else
            {
                cout << tab2D[j][i];
            }
        }
        cout << '|' << endl;
    }
    cout << '+';
    for (int k = 0; k < kMax_x; ++k)
    {
        cout << '-';
    }
    cout << '+' << endl;
    sleep(1);
}

void Monde::bouge(int anim_choisi)
{
    int direction = rand() % 4;

    Animal* animal = tab_anim[anim_choisi];
    if (!animal->getE() == 0)
    {
        switch (direction)
        {
        case 0: //Vers la gauche
            if (animal->getX() > 0 && tab2D[animal->getY()][animal->getX()-1] != animal->getLettre())
            {
                tab2D[animal->getY()][animal->getX()] = ' ';
                animal->setX(animal->getX()-1);
                animal->setE(animal->getE()-1);
                cout << "\nVers la gauche";
            }
            else if (animal->getX() == 0) cout << "\nLeft border reached";
            else cout << "\nAnimal on the left";
            break;

        case 1: //Vers le bas
            if (animal->getY() < kMax_y-1 && tab2D[animal->getY()+1][animal->getX()] != animal->getLettre())
            {
                tab2D[animal->getY()][animal->getX()] = ' ';
                animal->setY(animal->getY()+1);
                animal->setE(animal->getE()-1);
                cout << "\nVers le bas";
            }
            else if (animal->getY() == kMax_y-1) cout << "\nBottom border reached";
            else cout << "\nAnimal at the bottom";
            break;

        case 2: //Vers la droite
            if (animal->getX() < kMax_x-1 && tab2D[animal->getY()][animal->getX()+1] != animal->getLettre())
            {
                tab2D[animal->getY()][animal->getX()] = ' ';
                animal->setX(animal->getX()+1);
                animal->setE(animal->getE()-1);
                cout << "\nVers la droite";
            }
            else if (animal->getX() == kMax_x-1) cout << "\nRight border reached";
            else cout << "\nAnimal on the right";
            break;

        case 3: //Vers le haut
            if (animal->getY() > 0 && tab2D[animal->getY()-1][animal->getX()] != animal->getLettre())
            {
                tab2D[animal->getY()][animal->getX()] = ' ';
                animal->setY(animal->getY()-1);
                animal->setE(animal->getE()-1);
                cout << "\nVers le haut";
            }
            else if (animal->getY() == 0) cout << "\nTop border reached";
            else cout << "\nAnimal at the top";
            break;

        default:
            break;
        }

        tab2D[animal->getY()][animal->getX()] = animal->getLettre();

        if (animal->getE() == 0)
        {
            tab2D[animal->getY()][animal->getX()] = 'X';
            tab_anim.erase(tab_anim.begin() + anim_choisi);
        }
    }
}


#include "Animal.h"
#include <memory>
int main()
{
    int nb_animaux = 100;
    vector<unique_ptr<Animal>> tab_animal;
    //peuplement
    for (int i = 0; i < nb_animaux;
        tab_animal.push_back(make_unique<Animal>());
    }
    affichage
    for auto &anim : tab_animal
        anim->affiche();
    }
}