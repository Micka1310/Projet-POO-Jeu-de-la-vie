// ================
// | Classe "Case" |
// ================
//
// Auteur : King Mickaël
// 
// case.h : Ce fichier permet de déclarer la classe "Case", ses attributs ainsi que ses méthodes.
// 
// Permet de créer des cases pour remplir la grille.

#pragma once

// début de l'include guard
#ifndef CLASSE_CASE 
#define CLASSE_CASE

#include <iostream>

class Case
{

private:
	// attributs
	int m_coord_x;
	int m_coord_y;
	bool m_etat;

public:
	// constructeur
	Case();
	Case(int x, int y, bool etat);
	
	// destructeur
	~Case();

	// accesseur
	int getCoord_x();
	int getCoord_y();
	bool getEtat();

	// mutateur
	void setCoord_x(int x);
	void setCoord_y(int y);
	void setEtat(bool etat);

	// méthode
	void afficherCase() const;
};

#endif   // fin de l'include guard
