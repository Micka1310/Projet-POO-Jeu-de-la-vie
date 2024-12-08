#include "case.h"
#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;


class Grille {
private:
    string filename;
public:
    int rows, cols;
    vector<vector<Case>> grille; // Tableau dynamique 2D
    vector<vector<int>> grid; // Tableau dynamique 2D pour le graphique

    Grille(); // Constructeur par d�faut
    Grille(int r, int c);

    void getTaille();                                           // Afficher ou modifier la taille
    void ajouterLignesColonnes(int ajoutRows, int ajoutCols);
    void compter_voisin();                                      // Afficher ou modifier la taille
<<<<<<< HEAD
    void afficherGrille();                                      // Afficher la grille enti�re
=======
    void afficherGrille();                                      // Afficher la grille entière
>>>>>>> 19ceb25b456b457f440fbc76846cf8461b1181a2
    void PlacerPoint();                                         // Placer un point dans la grille

    void setFilename(const string& f) { filename = f; }
    void getTailleFichier();
    bool chargerGrilleDepuisFichier(const string& filename, vector<vector<Case>>& grille);
};
