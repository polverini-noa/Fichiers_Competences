#include <iostream>
#include <list>
#include <string>
#include <vector>

#ifndef Point_HPP
#define Point_HPP

// commande pour compiler :
// g++ Point.cpp Forme.cpp main.cpp -o main

class Point {
    private:
        float calc_x, calc_y;
        float x, y;
        int code; // normalement nous devons mettre ici le "const" mais quand "const" est la il ne veut plus compiler
        std::list<int> liste_code; // liste vide 
        std::string nom;
    public :

        Point(float x, float y, int code, std::list<int> liste_code, std::string nom);
        Point(int code, std::list<int> liste_code);
        Point();
        Point(Point &p, int code, std::list<int> liste_code);

        void affiche();

        float distance(Point pt);

        Point saisir();

        Point translater(Point Trans);

        static Point milieu(Point P1, Point P2);

        int getCode(Point P1);

        std::string getName(Point P1);
        Point setName(Point P1);
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
};

#endif