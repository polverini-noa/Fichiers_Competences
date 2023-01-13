// POLVERINI Noa

#include <iostream>
#include <vector>
#include "moteur.hpp"
using namespace std;
// include nécéssaire pour la fonction sleep
#include <cstdlib>
#include <unistd.h>

// Fichier moteur.cpp comprenant toutes les méthodes et constructeurs déclaré dans le fichier moteur.hpp

// Constructeurs
moteur::moteur(){
    this->nb_lignes = 3;
    this->nb_colonnes = 3;
    for (size_t i = 0; i < nb_colonnes; i++)
    {
        for (size_t j = 0; j < nb_lignes; j++)
        {
            this->grille.push_back(cellule());
        }
    }
}

moteur::moteur(int nb_lignes, int nb_colonnes){
    this->nb_lignes = nb_lignes;
    this->nb_colonnes = nb_colonnes;
    for (size_t i = 0; i < nb_colonnes; i++)
    {
        for (size_t j = 0; j < nb_lignes; j++)
        {
            this->grille.push_back(cellule());
        }
    }
}

// méthodes et fonctions
void moteur::add_vie(int num_cell){
    this->grille.at(num_cell).set_N(true);
}

// Méthode non utlisé mais qui peut être utile 
bool moteur::verif_coins(int num_cell){
    int nb_cases_total = this->nb_colonnes * this->nb_lignes;

    if (num_cell == 0 || num_cell == this->nb_lignes-1 || num_cell == nb_cases_total-1 || num_cell == nb_cases_total-(this->nb_lignes-1)){
        return true;
    }
    return false;
}
   
// Méthode non utlisé mais qui peut être utile 
bool moteur::verif_bordure(int num_cell){
    if (num_cell == 0 || num_cell == this->nb_lignes-1){
        return true;
    }
    return false;
}

// getters
int moteur::get_Y(int num_cell){
    this->pos_y = num_cell / this-> nb_colonnes;  // y 

    return pos_y;
}

int moteur::get_X(int num_cell){
    this->pos_x = num_cell % nb_colonnes ; // X
    // verif ici par rapport a photo du 17/10 et x en bas et y en haut
    return pos_x;
}

// Calcul le nombre de voisins
int moteur::nb_voisins(int cell, bool thor){

    // verif des coins
    if(cell==0){  // haut gauche
        compteur_voisins = 0;
        if (this->grille.at(cell+1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        } 
        if (this->grille.at(cell+nb_colonnes).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+nb_colonnes+1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }

        if (thor==true){
            // coin bas gauche
            if (this->grille.at(((nb_colonnes*nb_lignes)-nb_colonnes)).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // coin bas_gauche + 1
            if (this->grille.at(((nb_colonnes*nb_lignes)-nb_colonnes)+1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // coin haut droit
            if (this->grille.at(nb_colonnes-1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // en dessous de coin haut droit
            if (this->grille.at((nb_colonnes*2)-1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // coin bas droite
            if (this->grille.at(nb_colonnes*nb_lignes-1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
        }
    }

    else if (cell==nb_colonnes-1){ // droite haut
        compteur_voisins = 0;
        if (this->grille.at(cell-1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+nb_colonnes).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+nb_colonnes-1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }

        if (thor==true){
            // coin bas droite
            if (this->grille.at(((nb_colonnes*nb_lignes)-1)).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // coin bas droite - 1
            if (this->grille.at((nb_colonnes*nb_lignes)-2).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // coin haut gauche
            if (this->grille.at(0).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // en dessous de coin haut gauche
            if (this->grille.at(nb_colonnes).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // coin bas gauche
            if (this->grille.at((nb_colonnes*nb_lignes)-nb_colonnes).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
        }
    }

    else if (cell==(nb_colonnes*nb_lignes)-1){   // bas droite
        compteur_voisins = 0;
        if (this->grille.at(cell-1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell-nb_colonnes).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell-nb_colonnes-1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }

        if (thor==true){
            // coin haut droite
            if (this->grille.at((nb_colonnes)-1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // coin haut droite - 1
            if (this->grille.at(nb_colonnes-2).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // coin bas gauche
            if (this->grille.at((nb_colonnes*nb_lignes)-nb_colonnes).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // au dessus de coin bas gauche
            if (this->grille.at((nb_colonnes*nb_lignes)-(2*nb_colonnes)).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // coin haut gauche
            if (this->grille.at(0).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
        }
    }

    else if (cell==((nb_colonnes*nb_lignes)-nb_lignes)){   // bas gauche
        compteur_voisins = 0;
        if (this->grille.at(cell+1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell-nb_colonnes).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell-nb_colonnes+1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }

         if (thor==true){
            // coin haut gauche
            if (this->grille.at(0).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // coin haut gauche + 1
            if (this->grille.at(1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // coin bas droite
            if (this->grille.at((nb_colonnes*nb_lignes)-1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // au dessus de coin bas droite
            if (this->grille.at((nb_colonnes*nb_lignes)-(nb_colonnes+1)).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // coin haut droit
            if (this->grille.at(nb_colonnes-1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
        }
    }

    // vérifier les bordures      // ne pas oublier le thor en gros tu plie le truc en 4 pour que ca coordonne quand on plit
    else if (get_Y(cell) == 0){
        compteur_voisins = 0;
        if (this->grille.at(cell-1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+nb_colonnes-1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+nb_colonnes).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+nb_colonnes+1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }

        if (thor==true){
            // opposé bas
            if (this->grille.at(get_X(cell)+(nb_colonnes*nb_lignes)-nb_colonnes).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // opposé bas - 1
            if (this->grille.at((get_X(cell)+(nb_colonnes*nb_lignes)-nb_colonnes)-1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // opposé bas + 1
            if (this->grille.at((get_X(cell)+(nb_colonnes*nb_lignes)-nb_colonnes)+1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
        }
    }
    // bordure gauche
    else if (get_X(cell) == 0){
        compteur_voisins = 0;
        if (this->grille.at(cell-nb_colonnes).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell-nb_colonnes+1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+nb_colonnes).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+nb_colonnes+1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }

        if (thor==true){
            // opposé droit
            if (this->grille.at(cell+(nb_colonnes-1)).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // opposé droit - 1
            if (this->grille.at(cell-1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // opposé droit + 1
            if (this->grille.at(cell+(nb_colonnes*2)-1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
        }
    }
    // bordure droite
    else if (get_X(cell) == nb_colonnes-1){
        compteur_voisins = 0;
        if (this->grille.at(cell-nb_colonnes).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell-nb_colonnes-1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell-1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+nb_colonnes).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+nb_colonnes-1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }

        if (thor==true){
            // opposé gauche
            if (this->grille.at(cell-(nb_colonnes-1)).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // opposé gauche - 1
            if (this->grille.at(cell+1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // opposé gauche + 1
            if (this->grille.at(cell-(nb_colonnes*2)+1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
        }
    }
    // bordure basse
    else if (get_Y(cell) == nb_lignes-1){
        compteur_voisins = 0;
        if (this->grille.at(cell-1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell-nb_colonnes).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell-nb_colonnes-1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell-nb_colonnes+1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }

        if (thor==true){
            // opposé haut
            if (this->grille.at(get_X(cell)).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // opposé haut - 1
            if (this->grille.at(get_X(cell)-1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
            // opposé haut + 1
            if (this->grille.at(get_X(cell)+1).get_N() == true){
                compteur_voisins = compteur_voisins + 1;
            }
        }
    }

    // uen fois tous les cas spéciaux traité, on gère les cases "normales"
    else {
        compteur_voisins = 0;
        if (this->grille.at(cell-1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell-nb_colonnes).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell-nb_colonnes-1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell-nb_colonnes+1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+nb_colonnes).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+nb_colonnes-1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
        if (this->grille.at(cell+nb_colonnes+1).get_N() == true){
            compteur_voisins = compteur_voisins + 1;
        }
    }
    return compteur_voisins;
}

// actualise la grille en mettant la grille actualiser dans les valeurs N+1 des cellules
void moteur::actualiser(bool thor){

    for (size_t i = 0; i < grille.size()-1; i++)
    {
        if (grille.at(i).get_N() == true){       // vérifie si la case actuelle est vivante
            if ((this->nb_voisins(i, thor)==2) || (this->nb_voisins(i, thor)==3)){
                grille.at(i).set_N_1(true);
            }
            else {
                grille.at(i).set_N_1(false);
            }
        }

        else {       // case non vivante
            if (this->nb_voisins(i, thor)==3){
                grille.at(i).set_N_1(true);
            }
            else {
                grille.at(i).set_N_1(false);
            }
        }
    }
}

// Méthode qui n'est pas forcément utile, puisqu'il y à la méthode affiche_grille()
void moteur::afficher(){
    for (size_t i = 0; i < grille.size(); i++)
    {
        std::cout << grille.at(i).get_N() << endl;
    }
}

// Affiche uniquement les valeurs de N+1
void moteur::afficher_N_1(){
    for (size_t i = 0; i < grille.size(); i++)
    {
        std::cout << grille.at(i).get_N_1() << endl;
        grille.at(i).set_N(grille.at(i).get_N_1());
    }
}

// Fonction qui passe les valeurs de N+1 à N dans les cellules pour pouvoir recommencer le principe d'actualisation
void moteur::passage_n_1_vers_n(){
    for (size_t i = 0; i < grille.size(); i++)
    {
        grille.at(i).set_N(grille.at(i).get_N_1());
    }
}

// fonction affichant quelques statistiques après chaque itération dans le jeu 
void moteur::statistiques(){
    compteur_stats = 0;
    for (size_t i = 0; i < nb_colonnes*nb_lignes; i++)
    {
        if (this->grille.at(i).get_N()==true){
            compteur_stats++;
        }
    }
    pourcentage = nb_lignes*nb_colonnes;
    pourcentage = compteur_stats/pourcentage;
    std::cout << "Nombre de cellulles vivantes : " << compteur_stats << endl;
    std::cout << "Nombre de cellulles mortes : " << (nb_colonnes*nb_lignes)-compteur_stats << endl;
    std::cout << "Pourcentage d'occupations : " << pourcentage*100 << "%" << endl; 
}

// fonction qui permet de lancer les itérations à l'infini, pour stopper appuyer sur CTRL + C
void moteur::jeu(bool thor){
    while (1>0){
        this->affiche_grille();
        std::cout << "\nACTUALISATION...  (CTRL + C pour stop)\n" << endl;
        this->statistiques();
        this->actualiser(thor);
        this->passage_n_1_vers_n();
        sleep(3);  // temps d'attente entre chaque actualisation
        
    }
}

// Cette fonction est nécéssaire pour un affichage plus propre dans la console
string moteur::affiche_ligne(){
    compte_nb_colonnes = 0;
    string ligne = "";
    while(compte_nb_colonnes < nb_colonnes){
        ligne = ligne + "+-";
        compte_nb_colonnes++;
    }
    compte_nb_lignes++;
    if (compte_nb_lignes==nb_lignes+1){ 
        ligne = ligne + "+\n"; 
    }
    else { 
        ligne = ligne + "+\n" + "|"; 
    }
    return ligne;
}

// Affiche la grille 
string moteur::affiche_grille(){
    compteur_case_lignes = 0;
    compte_nb_lignes = 0;
    std::cout << affiche_ligne();
    for (size_t num_cell = 0; num_cell < nb_colonnes*nb_lignes; num_cell++)
    {
        if (compteur_case_lignes==nb_colonnes){
            std::cout << "\n";
            std::cout << affiche_ligne();
            compteur_case_lignes = 0;
        }
        if (this->grille.at(num_cell).get_N()==true){
            std::cout <<"@" << "|";
        }
        else {
            std::cout << " "<< "|";
        }
        compteur_case_lignes ++;   
    }
    std::cout << "\n"+affiche_ligne();
    return "";
}

// Calculs et affiche la grille obtenue après n itérations.
void moteur::calcul_n_iterations(int n, bool thor){
    for (size_t i = 0; i < n; i++)
    {
        this->actualiser(thor);
        this->passage_n_1_vers_n();
    }
    this->affiche_grille();
}

