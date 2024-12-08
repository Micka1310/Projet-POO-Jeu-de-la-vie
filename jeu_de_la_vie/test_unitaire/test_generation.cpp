#include "../Generation.cpp"
#include "../Generation.h"

int main() {
    {
        // Objet Generation créé dans un bloc
        Generation gen(100);

        while (!gen.estTerminee()) {
            gen.afficherGeneration();
            gen.incrementer();
        }
    } // L'objet "gen" sort ici de sa portée et est détruit

    std::cout << "Fin du programme." << std::endl;

    return 0;
}
