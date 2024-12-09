#pragma once
#include <iostream>
class Generation {
private:
    int generation;  // Num de la generation
    int max_gen;     // Nombre max de générations

public:
    // Constructeur 
    Generation(int maxGenerations);

    // Constructeur 
    ~Generation();

    // Méthode incrémenter génération
    void incrementer();
    // Méthode pour comparer la génération avec max
    bool estTerminee() const;
    int getGeneration() const;
    int getMaxGeneration() const;
    void arreter();
    // Affichage des informations de la génération
    void afficherGeneration() const;
};
