#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
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



//todo: пройтись по всем комментам + коммитнуть


int main() {
	unsigned  width = 1920;
	unsigned  height = 1080;
	sf::RenderWindow window(sf::VideoMode({width, height}), "Title");
	window.setFramerateLimit(100);


	sf::Image image;
	image.resize({width, height});

	sf::Texture texture(image.getSize());

	//что этим задается
	sf::Sprite sprite(texture);


	unsigned int size = width * height;


	//почему через * создается и почему после = хуйня какая то
	unsigned int *board = new unsigned int[size];
	unsigned int *neighbors = new unsigned int[size];


	//что тут вообще происходит
	int dir[8] =
	{
	1,
	int(width) + 1,
	int (width),
	int(width) -1,
	-1,
	-int(width) - 1,
	-int(width),
	-int(width) + 1
	};




	while(window.isOpen()){


		//посмотреть трезвым взглядом на все это
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
		window.draw(sprite);


		window.display();
	}
	//почему []
	delete[] board;
	delete[] neighbors;

	return 0;
}
