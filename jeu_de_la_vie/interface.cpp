    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <string>

    class Interface { 
    private:
        sf::RenderWindow window;
        int cellSize;
        int width, height;

    public:
        // Constructeur
        Interface(int gridWidth, int gridHeight, int cellSize = 20)
            : width(gridWidth), height(gridHeight), cellSize(cellSize) {
            window.create(sf::VideoMode(gridWidth * cellSize, gridHeight * cellSize), "Jeu de la vie");
            window.setFramerateLimit(60);
        }

        // console
        void afficherConsole(const std::vector<std::vector<bool>>& grid) {
            for (const auto& row : grid) {
                for (bool cell : row) {
                    std::cout << (cell ? "1 " : "0 ");
                }
                std::cout << '\n';
            }
            std::cout << std::string(30, '-') << '\n';
        }

        // fenêtre graphique
        void afficherGraphique(const std::vector<std::vector<bool>>& grid) {
            window.clear(sf::Color::Black);

            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
                    cell.setPosition(j * cellSize, i * cellSize);
                    cell.setFillColor(grid[i][j] ? sf::Color::White : sf::Color::Black);
                    window.draw(cell);
                }
            }
            window.display();
        }


        bool estOuverte() const {
            return window.isOpen();
        }


        void gererEvenements() {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
        }


        void attendre(int ms) const {
            sf::sleep(sf::milliseconds(ms));
        }


        ~Interface() {
            if (window.isOpen()) {
                window.close();
            }
        }
    };
