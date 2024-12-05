#include "case.h"
#pragma once
#include <iostream>
#include <vector>


class Grille {
private:
    Case* OCase;
public:
    int rows, cols; 
    std::vector<std::vector<Case>> grille; // Tableau dynamique 2D

    Grille(); // Constructeur par défaut
    Grille(int r, int c);

    void getTaille();        // Afficher ou modifier la taille
    void compter_voisin ();   // Afficher ou modifier la taille
    void afficherGrille();   // Afficher la grille entière
    void PlacerPoint();      // Placer un point dans la grille
};
