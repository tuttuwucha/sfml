#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <cmath>
#include <random>
#include <chrono>






int main() {
	unsigned  width = 500;
	unsigned  height = 800;
	sf::RenderWindow window(sf::VideoMode({width, height}), "Vertical Scrolling Rhythm Game ");
	window.setFramerateLimit(100);








	while(window.isOpen()){

		while(const std::optional event = window.pollEvent()) {
			if(event->is<sf::Event::Closed>()){

				window.close();
			}
			else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){

				if(keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
					window.close();
				}

			}
		}





		//render
		window.clear();

		//drawing



		window.display();
	}


	return 0;
}
