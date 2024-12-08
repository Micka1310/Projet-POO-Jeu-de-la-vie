#include "Grille.h"

using namespace std;

// Constructeur par défaut
Grille::Grille() : rows(0), cols(0), grille(0, vector<Case>(0)) { }

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
    cout << "\n     "; // Espace pour aligner avec les numéros de lignes
    for (size_t col = 0; col < grille[0].size(); ++col) {
        if (col < 9){
            cout << "--- ";
        } else if (col < 99) {
            cout << "-- ";
        } else {
            cout << "-";
        }
    
        
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

vector<vector<bool>> Grille::compter_voisin() {
    vector<vector<bool>> Save(rows, vector<bool>(cols, false));
    for (int x = 0; x <= rows - 1; x++) {
        for (int y = 0; y <= cols - 1; y++) {
            int nb_voisin = 0;
            if (x != 0 && y != 0 && grille[x - 1][y - 1].getEtat()) {
                nb_voisin++;
            }
            if (x != 0 && grille[x - 1][y].getEtat()) {
                nb_voisin++;
            }
            if (x != 0 && y != cols - 1 && grille[x - 1][y + 1].getEtat()) {
                nb_voisin++;
            }
            if (x != rows - 1 && y != 0 && grille[x + 1][y - 1].getEtat()) {
                nb_voisin++;
            }
            if (x != rows - 1 && grille[x + 1][y].getEtat()) {
                nb_voisin++;
            }
            if (x != rows - 1 && y != cols - 1 && grille[x + 1][y + 1].getEtat()) {
                nb_voisin++;
            }
            if (y != 0 && grille[x][y - 1].getEtat()) {
                nb_voisin++;
            }
            if (y != cols - 1 && grille[x][y + 1].getEtat()) {
                nb_voisin++;
            }
            // sauvegarder les changements d'états dans un tableau temporaire
            if (nb_voisin == 3 && !grille[x][y].getEtat()) {
                Save[x][y] = true;
            }
            else if ((nb_voisin == 3 || nb_voisin == 2) && grille[x][y].getEtat()) {
                Save[x][y] = true;
            }
            else {
                Save[x][y] = false;
            }
        }
    }
    //Récupérer les nouveaux états
    for (int x = 0; x <= rows - 1; x++) {
        for (int y = 0; y <= cols - 1; y++) {
            grille[x][y].setEtat(Save[x][y]);
        }
    }

    // Copier les états dans un tableau nommé "grid" pour le retour
    vector<vector<bool>> grid(rows, vector<bool>(cols));
    for (int x = 0; x < rows; x++) {
        for (int y = 0; y < cols; y++) {
            grid[x][y] = Save[x][y] ? 1 : 0;
        }
    }
    return grid;
}

//PARTIE AVEC FICHIER
void Grille::getTailleFichier() {
    
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erreur d'ouverture du fichier." << endl;
        while(true);
    }

    string line;

    if (getline(file, line))
    {
        istringstream iss(line);
        iss >> rows >> cols;
    }    

    // Redimensionner la grille
    grille.resize(rows, vector<Case>(cols)); // Crée une grille vide de dimensions rows x cols

    // Initialiser chaque case avec ses coordonnées
    for (int i = 0; i < rows; ++i) {
        if (getline(file, line)) { // Lire chaque ligne de la matrice
            istringstream iss(line);
            for (int j = 0; j < cols; ++j) {
                int etat;
                iss >> etat; // Lire l'état de chaque cellule (0 ou 1)
                grille[i][j] = Case(i, j, etat == 1); // Initialiser chaque case avec l'état lu
            }
        }
    }

    file.close();
    cout << "Le fichier contient " << rows << " lignes et " << cols << " colonnes." << std::endl;
    cout << "La grille a ete initialisée avec ses dimensions et cases." << endl;
}


vector<vector<int>> Grille::chargerGrilleDepuisFichier() {
    string filename = "C:/Users/tilal/Documents/CESI/DEUXIEME ANNEE/Livrables/Bloc POO/Livrable 2/jeu_de_la_vie_POO/jeu.txt";  // Chemin vers le fichier
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erreur d'ouverture du fichier." << endl;
        return {}; // Retourne une grille vide en cas d'erreur
    }

    string line;
    int rows, cols;
    vector<vector<int>> grille;

    // Lire les dimensions de la grille
    if (getline(file, line)) {
        istringstream iss(line);
        iss >> rows >> cols;
    }
    else {
        cerr << "Erreur de lecture des dimensions." << endl;
        return {}; // Retourne une grille vide en cas d'erreur
    }

    // Redimensionner la grille pour qu'elle corresponde aux dimensions lues
    grille.resize(rows, vector<int>(cols));

    // Lire les données et les stocker dans la grille
    for (int i = 0; i < rows; ++i) {
        if (getline(file, line)) { // Lire chaque ligne de la matrice
            istringstream iss(line);
            for (int j = 0; j < cols; ++j) {
                iss >> grille[i][j]; // Lire l'état de chaque cellule (0 ou 1)
            }
        }
        else {
            cerr << "Erreur de lecture des données de la grille." << endl;
            return {}; // Retourne une grille vide en cas d'erreur
        }
    }

    file.close();
    return grille; // Retourne la grille complète
}

