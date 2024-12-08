#pragma once
#include <iostream>
class Generation {
private:
    int generation;  // Num de la generation
    int max_gen;     // Nombre max de g�n�rations
public:
    // Constructeur
    Generation(int maxGenerations) : generation(0), max_gen(maxGenerations) {}
    // M�thode incr�menter g�n�ration
    void incrementer() {
        if (generation < max_gen) {
            generation++;
        }
    }
    // M�thode pour comparer la g�n�ration avec max
    bool estTerminee() const {
        return generation >= max_gen;
    }
    int getGeneration() const {
        return generation;
    }
    int getMaxGeneration() const {
        return max_gen;
    }
    void arreter() {
        generation = max_gen;
    }
    // Affichage des informations de la g�n�ration
    void afficherGeneration() const {
        std::cout << "Generation actuelle : " << generation + 1
            << " / Nombre maximum de generations : " << max_gen << std::endl;
    }
};
