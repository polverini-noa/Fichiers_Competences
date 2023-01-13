// POLVERINI Noa
#include <iostream>
#include "moteur.hpp"
#include "cellule.hpp"

// commande pour compiler et exécuter :
// g++ moteur.cpp cellule.cpp main.cpp -o main
// .\main

// ATTENTION DE BIEN Définir une grille avec un nombre de colonnes et de lignes égaux. 
// Exemple : 10 lignes, 10 colonnes.

// (N'ayant jamais réussi à lancer un fichier Qt Creator (étant sur Windows) 
// je n'ai pas pus l'utilisé pour la partie affichage, mais j'ai tout de même proposer une affichage de la grille plutôt correct :) )

int main(){
    // définitions du nombres de lignes et de colonnes pour les exemples en dessous.
    int nb_ligne = 7;
    int nb_colonne = 7;

    // Grille vide
    moteur grille_vide(nb_ligne, nb_colonne);

    // Grille pleine
    moteur grille_pleine(nb_ligne,nb_colonne);
    for (size_t i = 0; i < nb_ligne*nb_colonne; i++)
    {
        grille_pleine.add_vie(i);
    }   
    
    // Grille en Damier 
    moteur grille_damier(nb_ligne,nb_colonne);
    int compteur = 0;
    for (size_t i = 0; i < nb_colonne*nb_ligne; i++)
    {
        if (compteur==1){
            grille_damier.add_vie(i);
            compteur=0;
        }
        else {
            compteur++;
        }
    }

    // Grille aléaoire
    moteur grille_aleatoire(nb_ligne,nb_colonne);
    for (size_t i = 0; i < nb_colonne*nb_ligne; i++)
    {
        if ((rand() % 2)==0){   // Création d'une grille alétoire, en prenant un nombre aléatoire, si il est pair alors on ajoute une vie sinon non.
            grille_aleatoire.add_vie(i);
        }
    }

    // Afficher grille après 5 itérations : (décommentez la ligne en dessous pour essayer)
    // grille_damier.calcul_n_iterations(5, false);

    // Lancement du jeu sans le mode thor (passez la valeur thor à true pour jouer avec la fonctionnalité thor)
    bool thor = false;
    grille_damier.jeu(thor);
}