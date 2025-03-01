#include "animals.h"
#include "lion.h"
#include "gazelle.h"
#include "monde.h"

using namespace std;


int main()
{
    srand(time(NULL));

    Lion leo = Lion(3, 2, 5);
    Gazelle gazella = Gazelle(6, 3, 40);

    Monde world(2);

    world.peuplement();
    world.show();
    for (int i = 0; i < 15; ++i)
    {
        world.affiche();
        world.bouge(0);
        world.show();
    }
    world.affiche();
    return 0;
}