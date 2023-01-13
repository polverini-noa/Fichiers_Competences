#include "Forme.hpp"
#include "Point.hpp"
#include <iostream>
#include <vector>

// commande pour compiler :
// g++ Point.cpp Forme.cpp main.cpp -o main

Forme::Forme(){
    Point a(0,0,1,{}, "A");
    Point b(1,0,2,{}, "B");
    Point c(1,1,3,{}, "C");
    Point d(0,1,4,{}, "D");

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    vec.push_back(d);
}

Forme::Forme(std::vector<float> tab){
    Point a(tab[0],tab[1],1,{}, "A");
    Point b(tab[2],tab[3],2,{}, "B");
    Point c(tab[4],tab[5],3,{}, "C");
    Point d(tab[6],tab[7],4,{}, "D");

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    vec.push_back(d);
}

Forme::Forme(Forme &other){
    this->vec = other.vec;
}

void Forme::affiche(){
    for (auto i : vec){
        i.affiche();
    }
}

float Forme::perimetre(Forme F){
    float res ;
    for (int i; i < this->vec.size()-1; i++){
        res = res + this->vec.at(i).distance(this->vec.at(i++));
    }
    return res;
}

void Forme::deplace(float dx, float dy){
    for (auto i : vec){
        i.setX(i.getX()*dx);
        i.setY(i.getY()*dy);
    }
}
