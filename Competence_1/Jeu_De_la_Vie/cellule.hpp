// POLVERINI Noa

#include <iostream>
#include <vector>
using namespace std;

#ifndef cellule_HPP
#define cellule_HPP

// Fichier cellule.hpp déclarant toutes les méthodes et constructeurs qui sont dans le fichier cellule.cpp

class cellule {
    private:
        bool n, n_1;

    public :
        cellule();
        cellule(bool n, bool n_1);

        bool get_N();
        bool get_N_1();

        void set_N(bool n);
        void set_N_1(bool n_1);
};

#endif
