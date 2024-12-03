// ========================================
// | Test unitaire des biblioth�ques SFML |
// ========================================
//
// test_bibli_SFML.cpp : Ce fichier permet de faire un test unitaire pour v�rifier
// si les biblioth�ques sont bien installer et li� au fichier.
// 
// Le programme affiche une fen�tre si les biblioth�que SFML fonctionne correctement.

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}