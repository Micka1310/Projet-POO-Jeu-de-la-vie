// =================
// | Classe "Case" |
// =================
//
// case.cpp : Ce fichier permet de définir les méthodes de la classe "Case".

#include "case.h"


// constructeur
Case::Case() : m_coord_x(0), m_coord_y(0), m_etat(false)
{

};

// constructeur surcharger
Case::Case(int x, int y, bool etat) : m_coord_x(x), m_coord_y(y), m_etat(etat)
{

};

// destructeur
Case::~Case()
{

}

// accesseur
int Case::getCoord_x()
{
	return m_coord_x;
}

// accesseur
int Case::getCoord_y()
{
	return m_coord_y;
}

// accesseur
bool Case::getEtat()
{
	return m_etat;
}

// mutateur
void Case::setCoord_x(int x)
{
	m_coord_x = x;
}

// mutateur
void Case::setCoord_y(int y)
{
	m_coord_y = y;
}

// mutateur
void Case::setEtat(bool etat)
{
	m_etat = etat;
}

// méthode
void Case::afficherCase() const
{
	std::cout << "Coordonnee x : " << m_coord_x << std::endl;
	std::cout << "Coordonnee y : " << m_coord_y << std::endl;
	std::cout << "Etat de la case : " << m_etat << "\n" << std::endl;
}