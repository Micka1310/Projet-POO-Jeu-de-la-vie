#include "generation.h"

#include <iostream>

// Constructeur
Generation::Generation(int maxGenerations) : generation(0), max_gen(maxGenerations) {}

// Destructeur
Generation::~Generation() {
    std::cout << "Destructeur : L'objet Generation est detruit" << std::endl;
}

// Méthode incrémenter génération
void Generation::incrementer() {
    if (generation < max_gen) {
        generation++;
    }
}

// Méthode pour comparer la génération avec max
bool Generation::estTerminee() const {
    return generation >= max_gen;
}

int Generation::getGeneration() const {
    return generation;
}

int Generation::getMaxGeneration() const {
    return max_gen;
}

void Generation::arreter() {
    generation = max_gen;
}

// Affichage des informations de la génération
void Generation::afficherGeneration() const {
    std::cout << "Generation actuelle : " << generation + 1
        << " / Nombre maximum de generations : " << max_gen << std::endl;
}
