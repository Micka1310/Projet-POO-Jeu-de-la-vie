#include <iostream>
#include "Grille.h"
#include "Generation.h"

using namespace std;

int main()
{
    int choix = 1;
    Grille maGrille;
    maGrille.getTaille();
    maGrille.afficherGrille();
    while (choix == 1)
    {
        cout << "Voulez placer une case? :\n";
        cout << "1. Oui\n";
        cout << "0. Non\n";
        cout << "Votre choix : ";
        cin >> choix;
        if (choix == 1)
        {
            maGrille.PlacerPoint();
            maGrille.afficherGrille();
        }
    }
    // Initialisation avec un maximum de 10 générations
    Generation gen(10);
    
    while (!gen.estTerminee())
    {
        gen.afficherGeneration();
        maGrille.compter_voisin();
        maGrille.afficherGrille();
        gen.incrementer();
    }
    std::cout << "Le processus est termine." << std::endl;
    return 0;
}