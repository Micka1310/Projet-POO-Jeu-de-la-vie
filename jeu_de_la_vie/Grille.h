#include "case.h"
#pragma once
#include <iostream>
#include <vector>


class Grille {
private:
    int rows, cols; 
    std::vector<std::vector<Case>> grille; // Tableau dynamique 2D
public:
    Grille(); // Constructeur par défaut
    Grille(int r, int c);

    void getTaille();        // Afficher ou modifier la taille
    void compter_voisin ();   // Analyse les voisines de chaque case
    void afficherGrille();   // Afficher la grille entière
    void PlacerPoint();      // Placer un point dans la grille
};
