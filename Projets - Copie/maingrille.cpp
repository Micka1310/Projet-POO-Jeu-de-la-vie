#include <iostream>
#include "Grille.h"

int main() {
    int choix = 1;
    Grille maGrille;
    maGrille.getTaille();
    maGrille.afficherGrille();
    while (choix == 1){
        cout << "Voulez placer une case? :\n";
        cout << "1. Oui\n";
        cout << "0. Non\n";
        cout << "Votre choix : ";
        cin >> choix;
        if (choix == 1){
            maGrille.PlacerPoint();
            maGrille.afficherGrille();
        }
    }
    return 0;
}
