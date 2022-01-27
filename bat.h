#pragma once
#include "const.h"
#include "SFML/Graphics.hpp"

class Bat {
protected:
	sf::RectangleShape rect;
	float width = bat_width;
	float height = bat_height;
	float speedy = 10.f;
public:
	Bat(float startx, float starty);
	sf::RectangleShape getShape();
	float getWidth();
	float getHeight();
	float getSpeedy();
	sf::Vector2f getPosition();
	void setPosition(float x, float y);
	sf::FloatRect getHitBox();
};