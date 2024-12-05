#pragma once

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
	bool getEtat() const;

	// mutateur
	void setCoord_x(int x);
	void setCoord_y(int y);
	void setEtat(bool etat);

	// m�thode
	void afficherCase() const;
};




