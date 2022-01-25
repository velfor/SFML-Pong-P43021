#pragma once
#include "SFML/Graphics.hpp"

class Bat {
protected:
	sf::RectangleShape rect;
	float width = 25;
	float height = 100;
	float speedy = 10.f;
public:
	Bat(float startx, float starty);
	sf::RectangleShape getShape();
	float getWidth();
	float getHeight();
	float getSpeedy();
	sf::Vector2f getPosition();
	void setPosition(float x, float y);
};