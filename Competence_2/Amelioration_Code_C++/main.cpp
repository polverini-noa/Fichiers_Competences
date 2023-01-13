#include <iostream>
#include "Point.hpp"
#include "Forme.hpp"

// commande pour compiler :
// g++ Point.cpp Forme.cpp main.cpp -o main

int main(){
    // Liste de tests à commenter/décommenter à votre guise : 
    
    // std::cout << "Test constructeur par defaut" << std::endl;
    // Point test_defaut;
    // test_defaut.affiche();

    std::cout << "Test constructeur avec param" << std::endl;
    Point test_param(10,30,1000,{}, "Point1");
    test_param.affiche();

    Point test_param2(20,50, 1000, {}, "Point2");
    test_param2.affiche();

    // std::cout << "Test constructeur par copie" << std::endl;
    // Point test_copie(test_param);
    // test_copie.affiche();

    // std::cout << "Test pour trouver distance" << std::endl;
    // Point test_dist(20,50,1001);
    // test_dist.distance(test_param);

    // std::cout << "Test pour saisir les valeurs"  << std::endl;
    // test_param.saisir();
    
    // std::cout << "Test par translation" << std::endl;
    // test_param.translater(test_dist);

    // std::cout << "Test pour trouver le milieu" << std::endl;
    // Point P1(10,30,1002);
    // Point P2(30,60,1003);
    // test_param.milieu(P1, P2);
};