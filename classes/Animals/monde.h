#ifndef MONDE_H
#define MONDE_H

#include "animals.h"
#include <vector>


class Monde
{
    public:

        Monde(int nb_animaux);

        ~Monde();

        static int getkMax_x() {return kMax_x;};
        static int getkMax_y() {return kMax_y;};

        void peuplement();
        void affiche() const;
        void show() const;
        void bouge(int anim_choisi);

    private:

        int nb_animaux;
        static inline const int kMax_x = 25;
        static inline const int kMax_y = 10;
        char tab2D[kMax_y][kMax_x] {0};
        vector<Animal*> tab_anim;
};

#endif