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
<<<<<<< HEAD
    showcredits = false;
    maGrille.chargerGrilleDepuisFichier(filename, maGrille.grille);

    if (!maGrille.chargerGrilleDepuisFichier(filename, maGrille.grille)) {
        cerr << "Erreur : Chargement de la grille échoué !" << endl;
        return;
    }

    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("arriere.png")) {
        cerr << "Erreur : Impossible de charger l'image de fond." << endl;
        return;
    }

    const int WINDOW_WIDTH = 3000;
    const int WINDOW_HEIGHT = 1800;

    // Créer un sprite à partir de la texture
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Ajuster la taille du sprite à celle de la fenêtre (optionnel)
    FloatRect textureRect = backgroundSprite.getLocalBounds();
    backgroundSprite.setScale(
        static_cast<float>(WINDOW_WIDTH) / textureRect.width,
        static_cast<float>(WINDOW_HEIGHT) / textureRect.height
    );

=======
    maGrille.chargerGrilleDepuisFichier(filename, maGrille.grille);

    if (!maGrille.chargerGrilleDepuisFichier(filename, maGrille.grille)) {
        cerr << "Erreur : Chargement de la grille Ã©chouÃ© !" << endl;
        return;
    }

>>>>>>> 19ceb25b456b457f440fbc76846cf8461b1181a2
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            inputHandler(event, window);
        }

        window.clear(Color::White);
<<<<<<< HEAD
        window.draw(backgroundSprite);

        if (showcredits == true) {
            credits(window);
            txt.setPosition(window.getSize().x - txt.getLocalBounds().width, 200);
            window.draw(txt);
            window.display();
        }

        SetTxtTitre(txt, "BIENVENUE SUR LE JEU DE LA VIE");
        txt.setPosition(window.getSize().x / 2, 60); // En haut au centre
        window.draw(txt);

        if (drawButton(window, 100, 300, 350, 150, "Jouer en mode graphique", "ressources/lobster.ttf", Color::Cyan, Color::Black)) {
            for (int z = 0; z < 100; z++) {
                maGrille.compter_voisin();                          // Met à jour l'état de la grille
                gameGraph(window, maGrille.grille);                 // Redessine la grille avec l'état mis à jour
                gen.incrementer();                                  // Passe à la génération suivante
                this_thread::sleep_for(std::chrono::seconds(1));    // Pause de 1 seconde
                if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                    // Action lorsque Échap est pressée
                    window.close(); // fermer la fenêtre
                    return;
                }
            }
        }
        if (drawButton(window, 100, 800, 350, 150, "Jouer en mode console", "ressources/lobster.ttf", Color::Cyan, Color::Black)) {
            window.close();
        }
        if (drawButton(window, 100, 1300, 350, 150, "Crédits", "ressources/lobster.ttf", Color::Cyan, Color::Black)) {
            showcredits = true;
            window.display();
=======
        
        SetTxt(txt, "BIENVENUE SUR LE JEU DE LA VIE");
        window.draw(txt);

        if (drawButton(window, 100, 300, 200, 50, "Jouer en mode graphique", "ressources/lobster.ttf", Color::Green, Color::Black)) {
            for (int z = 0; z < 4; z++) {
                maGrille.compter_voisin();                          // Met Ã  jour l'Ã©tat de la grille
                gameGraph(window, maGrille.grille);                 // Redessine la grille avec l'Ã©tat mis Ã  jour
                gen.afficherGeneration();                           // Affiche la gÃ©nÃ©ration
                gen.incrementer();                                  // Passe Ã  la gÃ©nÃ©ration suivante
                this_thread::sleep_for(std::chrono::seconds(1));    // Pause de 1 seconde
            }
        }
        if (drawButton(window, 100, 400, 200, 50, "Jouer en mode console", "ressources/lobster.ttf", Color::Green, Color::Black)) {
            window.close();
        }
        if (drawButton(window, 100, 500, 200, 50, "CrÃ©dits", "ressources/lobster.ttf", Color::Green, Color::Black)) {
            credits(window);
            window.draw(txt);
>>>>>>> 19ceb25b456b457f440fbc76846cf8461b1181a2
        }

        window.display();
    }
}

<<<<<<< HEAD
void Interface::SetTxtTitre(Text& txt, string str) {
    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(60);
    txt.setFillColor(Color::White);
    txt.setStyle(Text::Bold | Text::Underlined);
    FloatRect textBounds = txt.getLocalBounds();
    txt.setOrigin(textBounds.width / 2, textBounds.top); // Centrage horizontal
}

void Interface::SetTxtCredits(Text& txt, string str) {
    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(60);
    txt.setFillColor(Color::White);
    txt.setStyle(Text::Bold | Text::Underlined);
    FloatRect textBounds = txt.getLocalBounds();
    txt.setOrigin(textBounds.width / 2, textBounds.top); // Centrage horizontal
}

=======
>>>>>>> 19ceb25b456b457f440fbc76846cf8461b1181a2
void Interface::SetTxt(Text & txt, string str) {
    txt.setFont(font);
    txt.setString(str);
    txt.setCharacterSize(26);
<<<<<<< HEAD
    txt.setFillColor(Color::White);
=======
    txt.setFillColor(Color::Black);
>>>>>>> 19ceb25b456b457f440fbc76846cf8461b1181a2
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

<<<<<<< HEAD
    static bool buttonPressed = false; // État du bouton (pas encore pressé)
    static bool mouseReleased = true; // Vérifier si le clic est relâché après appui
=======
    static bool buttonPressed = false; // Ã‰tat du bouton (pas encore pressÃ©)
    static bool mouseReleased = true; // VÃ©rifier si le clic est relÃ¢chÃ© aprÃ¨s appui
>>>>>>> 19ceb25b456b457f440fbc76846cf8461b1181a2

    if (Mouse::isButtonPressed(Mouse::Left)) {
        Vector2i mousePos = Mouse::getPosition(window);
        if (buttonShape.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
            if (mouseReleased && !buttonPressed) {
                buttonPressed = true;
                mouseReleased = false;
<<<<<<< HEAD
                return true; // Bouton cliqué une seule fois
=======
                return true; // Bouton cliquÃ© une seule fois
>>>>>>> 19ceb25b456b457f440fbc76846cf8461b1181a2
            }
        }
    }
    else {
<<<<<<< HEAD
        // Réinitialiser lorsque la souris est relâchée
=======
        // RÃ©initialiser lorsque la souris est relÃ¢chÃ©e
>>>>>>> 19ceb25b456b457f440fbc76846cf8461b1181a2
        mouseReleased = true;
        buttonPressed = false;
    }

    return false; // Aucun clic
}

void Interface::gameGraph(RenderWindow& window, const vector<vector<Case>>& grille) {
    if (maGrille.rows == 0 || maGrille.cols == 0) {
<<<<<<< HEAD
        cerr << "Erreur : La grille n'est pas initialisée !" << endl;
=======
        cerr << "Erreur : La grille n'est pas initialisÃ©e !" << endl;
>>>>>>> 19ceb25b456b457f440fbc76846cf8461b1181a2
        return;
    }
    for (size_t i = 0; i < grille.size(); ++i) {
        for (size_t j = 0; j < grille[i].size(); ++j) {
            RectangleShape caseShape(Vector2f(CASE_SIZE, CASE_SIZE));
            caseShape.setPosition(X_OFFSET + j * CASE_SIZE, Y_OFFSET + i * CASE_SIZE);
            caseShape.setFillColor(grille[i][j].getEtat() ? CASE_ALIVE_COLOR : CASE_DEAD_COLOR);
            window.draw(caseShape);

            // Ajouter une bordure pour chaque case
<<<<<<< HEAD
            caseShape.setOutlineThickness(1); // Ajustez l'épaisseur si nécessaire
=======
            caseShape.setOutlineThickness(1); // Ajustez l'Ã©paisseur si nÃ©cessaire
>>>>>>> 19ceb25b456b457f440fbc76846cf8461b1181a2
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