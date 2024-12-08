#include "interface_graphique.h"
#include "Grille.h"
#include "Generation.h"

using namespace sf;
using namespace std;

Interface::Interface(int largeur, int longueur) : largeur_fenetre(largeur), longueur_fenetre(longueur) {}

Grille maGrille;

Text txt;
Generation gen(20);

void Interface::MenuBase() {
    RenderWindow window(VideoMode(largeur_fenetre, longueur_fenetre), "Titre de la fenêtre");
    string filename = "C:/Users/tilal/Documents/CESI/DEUXIEME ANNEE/Livrables/Bloc POO/Livrable 2/jeu_de_la_vie_POO/jeu.txt";
    LoadFont();
    graphiqueActif = false;
    SetTxt(txt, "BIENVENUE SUR LE JEU DE LA VIE");
    vector<vector<int>> grid = maGrille.chargerGrilleDepuisFichier();

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            inputHandler(event, window);
        }

        window.clear(Color::White);
        

     

        if (drawButton(window, 100, 100, 200, 50, "Jouer en mode graphique", "ressources/lobster.ttf", Color::Green, Color::Black)) {
            for (int z = 0; z < 11; z++) {
                maGrille.compter_voisin();  // Met à jour l'état de la grille
                gameGraph(window, grid);  // Redessine la grille avec l'état mis à jour
                gen.afficherGeneration();  // Affiche la génération
                gen.incrementer();  // Passe à la génération suivante
                this_thread::sleep_for(std::chrono::seconds(1));  // Pause de 1 seconde
            }
        }
        if (drawButton(window, 100, 200, 200, 50, "Jouer en mode console", "ressources/lobster.ttf", Color::Green, Color::Black)) {
            window.close();
        }
        if (drawButton(window, 100, 300, 200, 50, "Crédits", "ressources/lobster.ttf", Color::Green, Color::Black)) {
            credits(window);
        }

        window.display();
    }
}

void Interface::SetTxt(Text& txt, string str) {
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
    buttonText.setCharacterSize(20);
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

vector < vector<int>> Interface::gameGraph(RenderWindow& window, vector<vector<int>>& grid) {
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            // Créer la forme de la case
            RectangleShape caseShape(Vector2f(CASE_SIZE, CASE_SIZE));
            caseShape.setPosition(X_OFFSET + j * CASE_SIZE, Y_OFFSET + i * CASE_SIZE);
            caseShape.setFillColor(grid[i][j] == 1 ? CASE_ALIVE_COLOR : CASE_DEAD_COLOR);

            // Dessiner la case
            window.draw(caseShape);

            // Dessiner la bordure de la case
            RectangleShape border(Vector2f(CASE_SIZE, CASE_SIZE));
            border.setPosition(X_OFFSET + j * CASE_SIZE, Y_OFFSET + i * CASE_SIZE);
            border.setFillColor(Color::Transparent);
            border.setOutlineThickness(2);
            border.setOutlineColor(BORDER_COLOR);

            window.draw(border);
        }
    }
    // Dessiner les bordures de la grille
    for (size_t i = 0; i <= grid.size(); ++i) {
        VertexArray line(Lines, 2);
        line[0].position = Vector2f(X_OFFSET, Y_OFFSET + i * CASE_SIZE);
        line[1].position = Vector2f(X_OFFSET + grid[0].size() * CASE_SIZE, Y_OFFSET + i * CASE_SIZE);
        line[0].color = BORDER_COLOR;
        line[1].color = BORDER_COLOR;
        window.draw(line);
    }
    for (size_t j = 0; j <= grid[0].size(); ++j) {
        VertexArray line(Lines, 2);
        line[0].position = Vector2f(X_OFFSET + j * CASE_SIZE, Y_OFFSET);
        line[1].position = Vector2f(X_OFFSET + j * CASE_SIZE, Y_OFFSET + grid.size() * CASE_SIZE);
        line[0].color = BORDER_COLOR;
        line[1].color = BORDER_COLOR;
        window.draw(line);
    }
    window.display();

    return grid;
}

void Interface::credits(RenderWindow& window) {
    // Liste des crédits
    vector<string> credits = {
        "Tilal MESSAOUDI",
        "Diego ODDOUX",
        "Bilel ROUABAH",
        "Mickael KING"
    };

    // Création d'une font pour le texte
    LoadFont();

    // Configuration des textes
    std::vector<Text> textes;
    for (const auto& credit : credits) {
        sf::Text text;
        text.setFont(font);
        text.setString(credit);
        text.setCharacterSize(24);
        text.setFillColor(Color::Black);
        text.setPosition(window.getSize().x - 200, 50 + textes.size() * 30);  // Positionne à droite
        textes.push_back(text);
    }

    // Affichage des crédits
    for (const auto& text : textes) {
        window.draw(text);
    }
    window.display();
}