#pragma once
#include "SFML/Graphics.hpp"

class TextObj {
private:
	sf::Font font;
	sf::Text text;
public:
	TextObj(std::string str, float x, float y, size_t size) {
		font.loadFromFile("ds-digi.ttf");
		text.setFont(font);
		text.setString(str);
		text.setCharacterSize(size);
		text.setFillColor(sf::Color::Yellow);
		text.setPosition(x,y);
	}
	sf::Text getText() { return text; }
	void update(std::string str) { text.setString(str); }
};

