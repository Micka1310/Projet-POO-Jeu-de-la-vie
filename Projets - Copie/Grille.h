#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Grille {
public:
    int rows, cols; 
    vector<vector<bool>> grille; // Tableau dynamique 2D

    Grille(); // Constructeur par défaut
    Grille(int, int);

    void getTaille();        // Afficher ou modifier la taille
    void afficherGrille();   // Afficher la grille entière
    void PlacerPoint();      // Placer un point dans la grille
};
