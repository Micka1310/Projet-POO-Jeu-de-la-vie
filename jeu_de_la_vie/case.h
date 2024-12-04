// ================
// | Classe "Case" |
// ================
//
// Auteur : King Micka�l
// 
// case.h : Ce fichier permet de d�clarer la classe "Case", ses attributs ainsi que ses m�thodes.
// 
// Permet de cr�er des cases pour remplir la grille.

#pragma once

// d�but de l'include guard
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

	// m�thode
	void afficherCase() const;
};

#endif   // fin de l'include guard
