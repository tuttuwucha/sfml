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


sf::Color HSVToRGB(float h, float s, float v) {
	// 1. Нормализуем отрицательный угол, если он пришел
	if (h < 0.0f) {
		h = std::fmod(h, 360.0f) + 360.0f;
	}

	// 2. ВСЕГДА ограничиваем s и v в пределах [0.0, 1.0] (вынесено из-под if)
	s = std::max(0.0f, std::min(1.0f, s));
	v = std::max(0.0f, std::min(1.0f, v));

	float hPrime = h / 60.0f;
	unsigned int hIndex = static_cast<unsigned int>(hPrime) % 6;

	float chroma = s * v;
	float minComponent = v - chroma; // Переименовали в minComponent для соответствия финалу
	float x = chroma * (1.0f - std::abs(std::fmod(hPrime, 2.0f) - 1.0f));

	float outRGB[6][3] = {
		{chroma, x,      0.0f},
		{x,      chroma, 0.0f},
		{0.0f,   chroma, x},
		{0.0f,   x,      chroma},
		{x,      0.0f,   chroma},
		{chroma, 0.0f,   x}
	};

	// 3. Переводим в диапазон [0, 255] с правильным округлением
	std::uint8_t rI = static_cast<std::uint8_t>(std::round((outRGB[hIndex][0] + minComponent) * 255.0f));
	std::uint8_t gI = static_cast<std::uint8_t>(std::round((outRGB[hIndex][1] + minComponent) * 255.0f));
	std::uint8_t bI = static_cast<std::uint8_t>(std::round((outRGB[hIndex][2] + minComponent) * 255.0f));

	return sf::Color(rI, gI, bI);
}



int main() {
	unsigned  width = 1920;
	unsigned  height = 1080;
	sf::RenderWindow window(sf::VideoMode({width, height}), "Title");
	window.setFramerateLimit(100);

	sf::VertexArray pixelGrid(sf::PrimitiveType::Points, width * height);

	// std::random_device rd;
	// std::mt19937 gen(rd());
	// std::uniform_real_distribution<float> distrib(1.0f, 360.0f);
	// float hue = distrib();
	// std::uniform_real_distribution<float> distrib(1.0f, 100.0f);


	for(int x = 0;  x < width; x++){
		for(int y = 0; y < height; y++){
			int index = x + y * width;

			pixelGrid[index].position = {static_cast<float>(x),static_cast<float>(y)};

			pixelGrid[index].color = HSVToRGB(210.0f, float(x) / width, 1.0f);
		}
	}



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

		window.draw(pixelGrid);

		window.display();
	}


	return 0;
}
