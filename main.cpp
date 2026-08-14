#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>


enum directions {down,right,up,left};
int main() {
	unsigned  width = 640;
	unsigned  height = 360;
	sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode({width, height}), "Title");
	window->setFramerateLimit(100);

	sf::Texture texture;

	if(!texture.loadFromFile("Sprites/ExampleSprite.png")) {

		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/ExampleSprite.png" << std::endl;
		return -1;
	}
	sf::Sprite sprite(texture);

	sf::IntRect dir[4];

	for(int i = 0; i < 4; i++){

		dir[i] = sf::IntRect({ {32* i, 0}, {32,32} });

	}

	sprite.setTextureRect(dir[down]);
	sprite.setOrigin({16,16});
	sprite.setPosition({width / 2.0f, height / 2.0f});

	while(window->isOpen()){

		while(const std::optional event = window->pollEvent()) {
			if(event->is<sf::Event::Closed>()){

				window->close();
			}
			else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){

				if(keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
					window->close();
				}
				else if (keyPressed->scancode == sf::Keyboard::Scancode::W) {
					sprite.setTextureRect(dir[up]);
					sprite.move({0,-16});
				}
				else if (keyPressed->scancode == sf::Keyboard::Scancode::S) {
					sprite.setTextureRect(dir[down]);
					sprite.move({0,16});
				}
				else if (keyPressed->scancode == sf::Keyboard::Scancode::D) {
					sprite.setTextureRect(dir[right]);
					sprite.move({16,0});
				}
				else if (keyPressed->scancode == sf::Keyboard::Scancode::A) {
					sprite.setTextureRect(dir[left]);
					sprite.move({-16,0});
				}
			}
		}


		//render
		window->clear();

		//drawing
		window->draw(sprite);

		window->display();
	}

	delete window;
	return 0;
}
