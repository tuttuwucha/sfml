#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

int main() {
	// В SFML 3 размеры передаются как единый вектор sf::Vector2u
	int width = 640;
	int height = 360;
	sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode({width, height}), "Title, nigga");
	window->setFramerateLimit(60);

	while(window->isOpen()){

		while(const std::optional event = window->pollEvent()) {
			if(event->is<sf::Event::Closed>()){

				window->close();
			}
			else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){

				if(keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
					window->close();
				}
			}
		}
		//render
		window->clear(sf::Color(0xFF9900FF));

		//drawing

		window->display();
	}

	delete window;
	return 0;
}
