#include "generation.h"

int main() {
    // Initialisation avec un maximum de 10 générations
    Generation gen(10);

    while (!gen.estTerminee()) {
        gen.afficherGeneration();
        gen.incrementer();
    }

    std::cout << "Le processus est termine." << std::endl;

    return 0;
}
