#include <iostream>
#include <fstream>
#include <string>
#include "Grille.h"
#include "Generation.h"
#include "interface_graphique.h"


using namespace std;

int main()
{
    Grille maGrille;
    Interface interface(2000, 1500);
    interface.MenuBase();

    cout << "0: Utiliser un fichier prédéfini\n1: Entrer les parametres manuellement\n" << endl;
    string filename = "jeu.txt";
    int choix1;
    cin >> choix1;
    if (choix1 == 0)
    {
        Generation gen(20);
        maGrille.setFilename(filename);
        maGrille.getTailleFichier();
        
        while (!gen.estTerminee()){    
            gen.afficherGeneration();
            maGrille.compter_voisin();
            maGrille.afficherGrille();
            gen.incrementer();
        }
    }
    else if (choix1 == 1) {
        int choix2 = 1;
        maGrille.getTaille();
        maGrille.afficherGrille();
        while (choix2 == 1) {
            cout << "Voulez placer une case? :\n";
            cout << "1. Oui\n";
            cout << "0. Non\n";
            cout << "Votre choix : ";
            cin >> choix2;
            if (choix2 == 1) {
                maGrille.PlacerPoint();
                maGrille.afficherGrille();
            }
        }
        int choix3;
        cout << "Veuillez entrer le nombre de generation pour la simulation :\n";
        cin >> choix3;
        Generation gen(choix3);
        while (!gen.estTerminee()) {
            gen.afficherGeneration();
            maGrille.compter_voisin();
            maGrille.afficherGrille();
            gen.incrementer();
            
        }
    }
    
    std::cout << "Le processus est termine." << std::endl;
    return 0;
}