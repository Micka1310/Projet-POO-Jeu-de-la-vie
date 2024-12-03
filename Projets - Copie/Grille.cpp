#include "Grille.h"

// Constructeur par défaut
Grille::Grille() : rows(0), cols(0), grille(0, vector<bool>(0)) {
    cout << "Grille par défaut" << endl;
}

// Constructeur paramétré
Grille::Grille(int r, int c) : rows(r), cols(c), grille(r, vector<bool>(c, false)) {
    cout << "Taille de la grille : " << rows << " x " << cols << endl;
}

// Modifier ou afficher la taille
void Grille::getTaille() {
    cout << "Début de la fonction" << endl;
    cout << "Entrez le nombre de lignes : ";
    cin >> rows;
    cout << "Entrez le nombre de colonnes : ";
    cin >> cols;

    // Redimensionner la grille
    grille.assign(rows, vector<bool>(cols, false));
}

// Afficher la grille
void Grille::afficherGrille() {
    cout << "Grille :" << endl;
    for (const auto& ligne : grille) {
        for (const auto& element : ligne) {
            cout << element << " "; // Affiche chaque élément de la ligne
        }
        cout << endl; // Passe à la ligne suivante
    }
}

// Placer un point dans la grille
void Grille::PlacerPoint() {
    int row, col;
    cout << "Points :" << endl;
    cout << "Entrez l'abscisse : ";
    cin >> row; // Abscisse
    cout << "Entrez l'ordonnée : ";
    cin >> col; // Ordonnée

    // Vérification des bornes
    if (row < 1 || row > rows || col < 1 || col > cols) {
        cout << "Erreur : Les coordonnées (" << row << ", " << col << ") sont hors de la grille." << endl;
        return;
    }

    if (grille[row - 1][col - 1] == false){
        grille[row - 1][col - 1] = true;
        cout << "La case a été placé à la ligne n°" << row << " et la colonne n°" << col-1 << " de la grille !" << endl;
    } else {
        grille[row - 1][col - 1] = false;
        cout << "La case a été enlevé à la ligne n°" << row << " et la colonne n°" << col-1 << " de la grille !" << endl;
    }
}
