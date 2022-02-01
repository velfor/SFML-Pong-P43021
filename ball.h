#pragma once
#include "SFML/Graphics.hpp"

class Ball {
private:
	sf::CircleShape circle;
	float radius = 10.f;
	float speedx = 3.5f;
	float speedy = 3.f;
	int left_score = 0;
	int right_score = 0;
	sf::Vector2f midtop;
	sf::Vector2f midbottom;
	sf::Vector2f midleft;
	sf::Vector2f midright;
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
	sf::FloatRect getHitBox();
	void reboundX();
	void reboundY();
	int getLeftScore();
	int getRightScore();
	sf::Vector2f getMidTop();
	sf::Vector2f getMidBottom();
	sf::Vector2f getMidLeft();
	sf::Vector2f getMidRight();
	void setPosition(float x, float y);
};