#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

int main() {
	unsigned  width = 1280;
	unsigned  height = 720;
	sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode({width, height}), "Title");
	window->setFramerateLimit(100);



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
		window->clear();

		//drawing


		window->display();
	}

	delete window;
	return 0;
}
