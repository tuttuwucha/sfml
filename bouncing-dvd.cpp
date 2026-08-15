#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>


enum class GameColor {
	White,
	Red,
	Green,
	Blue,
	Yellow,
	Magenta,
	Cyan
};
sf::Color getSFMLColor(GameColor color) {
	switch (color) {
		case GameColor::White:   return sf::Color::White;
		case GameColor::Red:     return sf::Color::Red;
		case GameColor::Green:   return sf::Color::Green;
		case GameColor::Blue:    return sf::Color::Blue;
		case GameColor::Yellow:  return sf::Color::Yellow;
		case GameColor::Magenta: return sf::Color::Magenta;
		case GameColor::Cyan:    return sf::Color::Cyan;
	}
	return sf::Color::White;
}
int main() {
	unsigned  width = 1440;
	unsigned  height = 720;
	sf::RenderWindow window(sf::VideoMode({width, height}), "Title");
	window.setFramerateLimit(100);

	sf::Texture texture;

	if(!texture.loadFromFile("Sprites/dvd-logo.png")) {

		std::cerr << "ERROR::COULD NOT LOAD FILE::Sprites/dvd-logo.png" << std::endl;
		return -1;
	}
	sf::Sprite sprite(texture);

	sprite.setOrigin({115,52});
	sprite.setPosition({width / 2.0f, height / 2.0f});

	sf::Vector2f velocity = {1.0f, 1.0f};

	int colorIndex = 0;
	

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

		sf::FloatRect bounds = sprite.getGlobalBounds();

		if(bounds.position.x < 0.0f){
			velocity.x = -velocity.x;
			colorIndex++;
		}
		if(bounds.position.x + bounds.size.x > width){
			velocity.x = -velocity.x;
			colorIndex++;
		}
		if(bounds.position.y < 0.0f){
			velocity.y = -velocity.y;
			colorIndex++;
		}
		if(bounds.position.y + bounds.size.y > height){
			velocity.y = -velocity.y;
			colorIndex++;
		}
		if (colorIndex > 7) {
			colorIndex -= 7;
		}

		sprite.setColor(getSFMLColor(static_cast<GameColor>(colorIndex)));






		sprite.move(velocity);


		//render
		window.clear();

		//drawing
		window.draw(sprite);

		window.display();
	}


	return 0;
}
