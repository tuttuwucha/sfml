#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>

int main() {
	unsigned  width = 640;
	unsigned  height = 360;
	sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode({width, height}), "Title");
	window->setFramerateLimit(100);

	sf::CircleShape circle(67.0f);
	circle.setOrigin(circle.getGeometricCenter());
	circle.setPosition({width / 2.0f, height / 2.0f});
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineThickness(3.0f);
	circle.setOutlineColor(sf::Color::White);
	circle.setPointCount(3);



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
		circle.rotate(sf::radians(1 / 67.0f));
		circle.move({1.0f, -2.0f});
		//render
		window->clear();

		//drawing
		window -> draw(circle);


		window->display();
	}

	delete window;
	return 0;
}
