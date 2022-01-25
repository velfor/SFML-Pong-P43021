#pragma once
#include "SFML/Graphics.hpp"

class Ball {
private:
	sf::CircleShape circle;
	float radius = 10.f;
	float speedx = 3.5f;
	float speedy = 3.f;
public:
	Ball();
	sf::CircleShape getShape();
	float getRadius();
	float getSpeedx();
	float getSpeedy();
	void setSpeedx(float fspeedx);
	void setSpeedy(float fspeedy);
	void update();
	sf::Vector2f getPosition();
};