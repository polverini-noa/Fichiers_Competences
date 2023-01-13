// POLVERINI Noa

#include <iostream>
#include <vector>
#include "cellule.hpp"
using namespace std;


#ifndef moteur_HPP
#define moteur_HPP

// Fichier moteur.hpp déclarant toutes les méthodes et constructeurs qui sont dans le fichier moteur.cpp

class moteur {
    private:
        std::vector<cellule> grille;
        int nb_lignes, nb_colonnes;
        int pos_x, pos_y;
        int compteur_voisins;
        int compte_nb_colonnes = 0;
        int compte_nb_lignes = 0;
        int compteur_case_lignes;
        
        int compteur_stats;
        float pourcentage;

    public :
    // constructeur
        moteur();
        moteur(int nb_lignes, int nb_colonnes);
    
    // méthodes
        void add_vie(int num_cell);

        bool verif_coins(int num_cell);
        bool verif_bordure(int num_cell);

        int nb_voisins(int cell, bool thor);
        void actualiser(bool thor);
        void afficher();
        void afficher_N_1();
        void passage_n_1_vers_n();
        void jeu(bool thor);
        string affiche_grille();
        string affiche_ligne();
        void calcul_n_iterations(int n, bool thor);
        void statistiques();

        int get_X(int num_cell);
        int get_Y(int num_cell);
};

#endif