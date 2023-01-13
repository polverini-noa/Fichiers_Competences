// POLVERINI Noa

#include <iostream>
#include <vector>
#include "cellule.hpp"
using namespace std;

// Fichier cellule.cpp comprenant toutes les méthodes et constructeurs présent dans le fichier cellule.hpp

// constructeurs
cellule::cellule(){
    this->n = false ;
    this->n_1 = false ;
}

cellule::cellule(bool n, bool n_1){
    this->n = n ;
    this->n_1 = n_1 ;
}

// getters
bool cellule::get_N(){
    return this->n;
}

bool cellule::get_N_1(){
    return this->n_1;
}

// setters
void cellule::set_N(bool n){
    this->n = n;
}

void cellule::set_N_1(bool n_1){
    this->n_1 = n_1;
}

