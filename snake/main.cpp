#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    // Размер игрового окна
    sf::RenderWindow window(sf::VideoMode({ 400, 400 }), "SFML window");

    // Старт игрового окна
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Очистка окна.
        window.clear();

        // Update the window
        window.display();
    }
}