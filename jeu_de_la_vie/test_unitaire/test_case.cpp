// =====================================
// | Test unitaire de la classe "Case" |
// =====================================
//
// Auteur : King Mickaël
// 
// test_case.cpp : Ce fichier permet de faire un test unitaire pour vérifier
// si la classe "Case" et ses méthodes fonctionnent correctement.
// 
// Le programme créer des objets de la classe "Case" et appelle les méthodes
// avec ces objets.

#include "../case.h"
#include "../case.cpp"

int main()
{
	// Création d'objet
	Case case_simple;
	Case case_surcharger(7, 24, true);

	// Test de méthode
	case_simple.afficherCase();
	case_surcharger.afficherCase();

	// Test d'accesseur
	int test_y = case_surcharger.getCoord_y();
	bool test_bool = case_surcharger.getEtat();

	std::cout << "Coordonnee y : " << test_y << std::endl;
	std::cout << "Statut de la case : " << test_bool << "\n" << std::endl;

	// Test de mutateur
	case_surcharger.setCoord_x(154);
	case_surcharger.setEtat(false);
	
	case_surcharger.afficherCase();

	std::cout << "Le test unitaire de la classe \"Case\" marche ! :)" << std::endl;

	return 0;
}