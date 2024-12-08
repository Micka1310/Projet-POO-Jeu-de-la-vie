#pragma once
#include "case.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include <thread>  // Pour this_thread::sleep_for
#include <chrono>  // Pour chrono::seconds
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

class Interface {
private:
    int largeur_fenetre;
    int longueur_fenetre;
    bool graphiqueActif;
<<<<<<< HEAD
    bool showcredits;
    Font font;

    const float CASE_SIZE = 25.0f; // Taille d'une case
    const float X_OFFSET = 900.0f; // D�calage de d�part horizontal
    const float Y_OFFSET = 200.0f; // D�calage de d�part vertical
=======
    Font font;

    const float CASE_SIZE = 20.0f; // Taille d'une case
    const float X_OFFSET = 440.0f; // Décalage de départ horizontal
    const float Y_OFFSET = 50.0f; // Décalage de départ vertical
>>>>>>> 19ceb25b456b457f440fbc76846cf8461b1181a2
    const Color CASE_ALIVE_COLOR = Color::Red; // Couleur des cellules vivantes
    const Color CASE_DEAD_COLOR = Color::Cyan;  // Couleur des cellules mortes
    const Color BORDER_COLOR = Color::Black;     // Couleur de la bordure des cases

public:
    Interface(int largeur, int longueur);
    void MenuBase();
    void SetTxt(Text& txt, string str);
<<<<<<< HEAD
    void SetTxtTitre(Text& txt, string str);
    void SetTxtCredits(Text& txt, string str);
=======
>>>>>>> 19ceb25b456b457f440fbc76846cf8461b1181a2
    void LoadFont();
    void inputHandler(Event& event, Window& window);
    bool drawButton(
        RenderWindow& window, float x, float y, float width, float height, const string& label, 
        const string& fontPath, Color bgColor = Color::Blue, Color textColor = Color::White
    );
    void credits(RenderWindow& window);
    void gameGraph(RenderWindow& window, const vector<vector<Case>>& grille);
};
