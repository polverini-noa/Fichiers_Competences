#include <iostream>
#include <list>
#include <vector>
#include "Point.hpp"

#ifndef Forme_HPP
#define Forme_HPP

// commande pour compiler :
// g++ Point.cpp Forme.cpp main.cpp -o main

class Forme {
    private:
        std::vector<Point> vec;
    public :
        Forme();
        Forme(std::vector<float> tab);
        Forme(Forme &F);
        void affiche();
        float perimetre(Forme F);
        void deplace(float dx, float dy);
};

#endif