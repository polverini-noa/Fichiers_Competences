#include "Point.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

// commande pour compiler :
// g++ Point.cpp Forme.cpp main.cpp -o main

Point::Point(int const code, std::list<int> liste_code):code(code)
{
    if (!liste_code.empty()){
        for (auto i : liste_code){
            if(i==code){
                std::cout << "Code déjà utilisé" << std::endl;
            }
        }
        this->x = 0;
        this->y = 0;
        this->nom = "Point";
        std::cout << "construct Point par défaut" << std::endl;
        liste_code.assign(1, code);
             
    }    
    else {
        this->x = 0;
        this->y = 0;
        this->nom = "Point";
        std::cout << "construct Point par défaut" << std::endl;
        liste_code.assign(1, code);
    }
}

Point::Point(float const x, float const y, int const code, std::list<int> liste_code, std::string nom):code(code)
{
    if (!liste_code.empty()){
        for (auto i : liste_code){
            if(i==code){
                std::cout << "Code déjà utilisé" << std::endl;
            }
        }
        this->x = x;
        this->y = y;
        this->nom = nom;
        std::cout << "construct Point avec param" << std::endl;
        liste_code.assign(1, code);
             
    }    
    else {
        this->x = x;
        this->y = y;
        this->nom = nom;
        std::cout << "construct Point avec param" << std::endl;
        liste_code.assign(1, code);
    }
}

Point::Point(Point &other, int const code, std::list<int> liste_code):code(code)
{
    if (!liste_code.empty()){
        for (auto i : liste_code){
            if(i==code){
                std::cout << "Code déjà utilisé" << std::endl;
                return ;
            }
        }
        this->x = other.x;
        this->y = other.y;
        this->nom = other.nom;
        std::cout << "construct Point par Recopie" << std::endl;
        liste_code.assign(1, code);
             
    }    
    else {
        this->x = other.x;
        this->y = other.y;
        this->nom = other.nom;
        std::cout << "construct Point par Recopie" << std::endl;
        liste_code.assign(1, code);
    }
} 

// méthodes & fonctions 

void Point::affiche(){
    std::cout << "Valeur de x : " << x << std::endl;
    std::cout << "Valeur de y : " << y << std::endl;
    std::cout << "Valeur du compteur : " << code << std::endl;
    std::cout << "Nom du point : " << nom << std::endl;
}

 
float Point::distance(Point const pt){
    calc_x = abs((this->x - pt.x));
    calc_y = abs((this->y - pt.y));
    
    return sqrt((pow(calc_x, 2) + pow(calc_y,2)));
}

Point Point::saisir(){
    std::cout << "Tapez coords en X: ";
    std::cin >> x;
    std::cout << "Tapez coords en Y: ";
    std::cin >> y;
    std::cout << "Tapez son nom : ";
    std::cin >> nom;
    std::cout << "Les valeurs du point sont : " << x << " ; " << y << std::endl;

    return Point(x,y,1000, liste_code, nom);
}

Point Point::translater(Point Trans){
    this->x = Trans.x;
    this->y = Trans.y;

    std::cout << "Les valeurs du point changes sont : " << x << " ; " << y << std::endl;
    return Point(x,y,1001, liste_code, nom);
}

Point Point::milieu(Point P1, Point P2){
    const float calc_x = (P1.x + P2.x)/2 ;
    const float calc_y = (P1.y + P2.y)/2 ;
    Point res(calc_x,calc_y, P1.code+P2.code, P1.liste_code, "Point Milieu" );

    return res;
}

int Point::getCode(Point P1){
    return P1.code;
}

std::string Point::getName(Point P1){
    return P1.nom;
}

Point Point::setName(Point P1){
    std::cout << "Tapez son nom : ";
    std::cin >> nom;

    return Point(P1.x,P1.y,P1.code, P1.liste_code, nom);
}


// Pour permettre le deplacement des points nous avions du créer les méthodes get Et set de base.
int Point::getX(){
    return x;
}
int Point::getY(){
    return y;
}
void Point::setX(int x_modif){
    x = x_modif;
}
void Point::setY(int y_modif){
    y = y_modif;
}