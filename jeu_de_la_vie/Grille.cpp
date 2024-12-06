#include "Grille.h"

using namespace std;

// Constructeur par défaut
Grille::Grille() : rows(0), cols(0), grille(0, vector<Case>(0)) {}

// Constructeur paramétré
Grille::Grille(int r, int c) : rows(r), cols(c), grille(r, vector<Case>(c)) {
    cout << "Taille de la grille : " << rows << " x " << cols << endl;
    
}

// Modifier ou afficher la taille
void Grille::getTaille() {
    cout << "Entrez le nombre de lignes : ";
    cin >> rows;
    cout << "Entrez le nombre de colonnes : ";
    cin >> cols;

    // Redimensionner la grille
    grille.resize(rows, vector<Case>(cols)); // Crée une grille vide de dimensions rows x cols

    // Initialiser chaque case avec ses coordonnées
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            grille[i][j] = Case(i, j, false); // Utilise le constructeur paramétré de Case
        }
    }

    cout << "La grille a ete initialisée avec ses dimensions et cases." << endl;
}

// Afficher la grille
void Grille::afficherGrille() {
    // Affichage des numéros de colonnes
    cout << "     "; // Espace pour aligner avec les numéros de lignes
    for (size_t col = 0; col < grille[0].size(); ++col) {
        if (col < 9){
            cout << col+1 << "  ";
        } else if (col < 99) {
            cout << col+1 << " ";
        } else {
            cout << col+1;
        }
    }
    cout << "\n    "; // Espace pour aligner avec les numéros de colonnes
    for (size_t col = 0; col < grille[0].size(); ++col) {
        cout << "---";   
    }
    cout << "\n";

    // Affichage de la grille avec numéros de lignes
    for (size_t row = 0; row < grille.size(); ++row) {
        if (row < 9){
            cout << row+1 << "  | "; // Numéro de ligne avec une barre pour séparer
        } else if (row <99){
            cout << row+1 << " | ";
        } else {
            cout << row+1 << "| ";
        }
        for (const auto& element : grille[row]) {
            cout << (element.getEtat() ? "1" : "0") << "  ";
        }
        cout << endl;
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
        cout << "Erreur : Les coordonnees (" << row << ", " << col << ") sont hors de la grille." << endl;
        return;
    }

    if (!grille[row - 1][col - 1].getEtat()){
        grille[row - 1][col - 1].setEtat(true);
        cout << "La case a ete place a la ligne n°" << row << " et la colonne n°" << col << " de la grille !" << endl;
    } else {
        grille[row - 1][col - 1].setEtat(false);
        cout << "La case a ete enleve a la ligne n°" << row << " et la colonne n°" << col << " de la grille !" << endl;
    }
}

void Grille::compter_voisin (){
    vector<vector<bool>> Save (rows, std::vector<bool>(cols, false));
    for (int x = 0; x <= rows-1; x++){
        for (int y = 0; y <= cols-1; y++){
            int nb_voisin = 0;
            if (x != 0 && y != 0 && grille[x-1][y-1].getEtat()){
                nb_voisin++;
            }
            if (x != 0 && grille[x-1][y].getEtat()){
                nb_voisin++;
            }
            if (x != 0 && y != cols-1 && grille[x-1][y+1].getEtat()){
                nb_voisin++;
            }
            if (x != rows-1 && y != 0 && grille[x+1][y-1].getEtat()){
                nb_voisin++;
            }
            if (x != rows-1 && grille[x+1][y].getEtat()){
                nb_voisin++;
            }
            if (x != rows-1 && y != cols-1 && grille[x+1][y+1].getEtat()){
                nb_voisin++;
            }
            if (y != 0 && grille[x][y-1].getEtat()){
                nb_voisin++;
            }
            if (y != cols-1 && grille[x][y+1].getEtat()){
                nb_voisin++;
            }
            // sauvegarder les changements d'états dans un tableau temporaire
            if (nb_voisin == 3 && !grille[x][y].getEtat()){
                Save[x][y] = true;
            } else if ((nb_voisin == 3 || nb_voisin == 2) && grille[x][y].getEtat()){
                Save[x][y] = true;
            } else {
                Save[x][y] = false;
            }
        }
    }
    //Récupérer les nouveaux états
    for (int x = 0; x <= rows-1; x++){
        for (int y = 0; y <= cols-1; y++){
            grille[x][y].setEtat(Save[x][y]);
        }
    }
}
