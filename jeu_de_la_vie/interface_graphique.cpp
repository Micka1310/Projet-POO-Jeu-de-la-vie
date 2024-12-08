#include "interface_graphique.h"
#include "grille.h"
#include "generation.h"
#include "case.h"

using namespace sf;
using namespace std;

Interface::Interface(int largeur, int longueur) : largeur_fenetre(largeur), longueur_fenetre(longueur) {}
Grille maGrille;
Text txt;
Generation gen(20);

void Interface::MenuBase() {
    //string filename = "C:/Users/tilal/Documents/CESI/DEUXIEME ANNEE/Livrables/Bloc POO/Livrable 2/jeu_de_la_vie_POO/jeu.txt";
    string filename = "jeu.txt";
    RenderWindow window(VideoMode(largeur_fenetre, longueur_fenetre), "Jeu de la vie");
    LoadFont();
    graphiqueActif = false;
    maGrille.chargerGrilleDepuisFichier(filename, maGrille.grille);

    if (!maGrille.chargerGrilleDepuisFichier(filename, maGrille.grille)) {
        cerr << "Erreur : Chargement de la grille échoué !" << endl;
        return;
    }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            inputHandler(event, window);
        }

        window.clear(Color::White);
        
        SetTxt(txt, "BIENVENUE SUR LE JEU DE LA VIE");
        window.draw(txt);

        if (drawButton(window, 100, 300, 200, 50, "Jouer en mode graphique", "ressources/lobster.ttf", Color::Green, Color::Black)) {
            for (int z = 0; z < 4; z++) {
                maGrille.compter_voisin();                          // Met à jour l'état de la grille
                gameGraph(window, maGrille.grille);                 // Redessine la grille avec l'état mis à jour
                gen.afficherGeneration();                           // Affiche la génération
                gen.incrementer();                                  // Passe à la génération suivante
                this_thread::sleep_for(std::chrono::seconds(1));    // Pause de 1 seconde
            }
        }
        if (drawButton(window, 100, 400, 200, 50, "Jouer en mode console", "ressources/lobster.ttf", Color::Green, Color::Black)) {
            window.close();
        }
        if (drawButton(window, 100, 500, 200, 50, "Crédits", "ressources/lobster.ttf", Color::Green, Color::Black)) {
            credits(window);
            window.draw(txt);
        }

        window.display();
    }
}

void Interface::SetTxt(Text & txt, string str) {
    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(26);
    txt.setFillColor(Color::Black);
    txt.setStyle(Text::Bold | Text::Underlined);
    
}

void Interface::LoadFont() {
    if (!font.loadFromFile("ressources/lobster.ttf")) {
        cerr << "Erreur de chargement de la police." << endl;
    }
}

void Interface::inputHandler(Event& event, Window& window) {
    if (event.type == Event::Closed) {
        window.close();
    }
}

bool Interface::drawButton(RenderWindow& window, float x, float y, float width, float height, const string& label, const string& fontPath, Color bgColor, Color textColor) {
    // Charger la police
    Font font;
    if (!font.loadFromFile(fontPath)) {
        cerr << "Erreur : Impossible de charger la police : " << fontPath << endl;
        return false; // Erreur de chargement
    }

    // Configurer la forme du bouton
    RectangleShape buttonShape(Vector2f(width, height));
    buttonShape.setPosition(x, y);
    buttonShape.setFillColor(bgColor);

    // Configurer le texte
    Text buttonText;
    buttonText.setFont(font);
    buttonText.setString(label);
    buttonText.setCharacterSize(30);
    buttonText.setFillColor(textColor);

    // Centrer le texte dans le bouton
    FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(textBounds.width / 2, textBounds.height / 2);
    buttonText.setPosition(x + width / 2, y + height / 2);

    // Dessiner le bouton
    window.draw(buttonShape);
    window.draw(buttonText);

    static bool buttonPressed = false; // État du bouton (pas encore pressé)
    static bool mouseReleased = true; // Vérifier si le clic est relâché après appui

    if (Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousePos = Mouse::getPosition(window);
        if (buttonShape.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
            if (mouseReleased && !buttonPressed) {
                buttonPressed = true;
                mouseReleased = false;
                return true; // Bouton cliqué une seule fois
            }
        }
    }
    else {
        // Réinitialiser lorsque la souris est relâchée
        mouseReleased = true;
        buttonPressed = false;
    }

    return false; // Aucun clic
}

void Interface::gameGraph(RenderWindow& window, const vector<vector<Case>>& grille) {
    if (maGrille.rows == 0 || maGrille.cols == 0) {
        cerr << "Erreur : La grille n'est pas initialisée !" << endl;
        return;
    }
    for (size_t i = 0; i < grille.size(); ++i) {
        for (size_t j = 0; j < grille[i].size(); ++j) {
            RectangleShape caseShape(Vector2f(CASE_SIZE, CASE_SIZE));
            caseShape.setPosition(X_OFFSET + j * CASE_SIZE, Y_OFFSET + i * CASE_SIZE);
            caseShape.setFillColor(grille[i][j].getEtat() ? CASE_ALIVE_COLOR : CASE_DEAD_COLOR);
            window.draw(caseShape);

            // Ajouter une bordure pour chaque case
            caseShape.setOutlineThickness(1); // Ajustez l'épaisseur si nécessaire
            caseShape.setOutlineColor(BORDER_COLOR);
            caseShape.setFillColor(Color::Transparent); // Bordure uniquement
            window.draw(caseShape);
        }
    }

    // Ajouter les lignes des bordures verticales entre les colonnes
    for (size_t j = 0; j <= grille[0].size(); ++j) {
        VertexArray line(Lines, 2);
        line[0].position = Vector2f(X_OFFSET + j * CASE_SIZE, Y_OFFSET);
        line[1].position = Vector2f(X_OFFSET + j * CASE_SIZE, Y_OFFSET + grille.size() * CASE_SIZE);
        line[0].color = BORDER_COLOR;
        line[1].color = BORDER_COLOR;
        window.draw(line);
    }

    window.display();
}

void Interface::credits(RenderWindow& window) {
    
    LoadFont();
    // Configuration des textes
    SetTxt(txt, "CREDITS :\n- Tilal MESSAOUDI \n- Mickael KING \n- Diego ODDOUX--AUBER\n- Bilel ROUABAH");
    window.display();
}