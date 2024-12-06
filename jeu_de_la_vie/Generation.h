#pragma once
#include <iostream>

class Generation {
private:
    int generation;  // Num de la generation
    int max_gen;     // Nombre max de g�n�rations

public:
    // Constructeur
    Generation(int maxGenerations);

    // Destructeur
    ~Generation();

    // M�thodes
    void incrementer();
    bool estTerminee() const;
    int getGeneration() const;
    int getMaxGeneration() const;
    void arreter();
    void afficherGeneration() const;
};
