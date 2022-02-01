#include "ball.h"
#include "const.h"

Ball::Ball() {
	circle.setRadius(radius);
	circle.setPosition(WINDOW_WIDTH / 2 - radius, WINDOW_HEIGHT / 2 - radius);
	circle.setFillColor(sf::Color::Yellow);
	//circle.setOutlineColor(sf::Color(240, 230, 140));
	//circle.setOutlineThickness(5);
}
sf::CircleShape Ball::getShape() { return circle; }
float Ball::getRadius() { return radius; }
float Ball::getSpeedx() { return speedx; }
float Ball::getSpeedy() { return speedy; }
void Ball::setSpeedx(float fspeedx) { speedx = fspeedx; }
void Ball::setSpeedy(float fspeedy) { speedy = fspeedy; }
sf::Vector2f Ball::getPosition() { return circle.getPosition(); }
sf::FloatRect Ball::getHitBox() { return circle.getGlobalBounds(); }
void Ball::reboundX() { speedx = -speedx; }
void Ball::reboundY() { speedy = -speedy; }
int Ball::getLeftScore() { return left_score; }
int Ball::getRightScore() { return right_score; }
void Ball::update() {
	circle.move(speedx, speedy);
	if (circle.getPosition().x <= 0) {
		right_score++;
		speedx = -speedx;
	}
	if (circle.getPosition().x >= WINDOW_WIDTH - 2*radius) {
		left_score++;
		speedx = -speedx;
	}
	if (circle.getPosition().y <= 0 ||
		circle.getPosition().y >= WINDOW_HEIGHT - 2 * radius) {
		speedy = -speedy;
	}
}
sf::Vector2f Ball::getMidTop() {
	midtop = sf::Vector2f(getPosition().x + radius, getPosition().y);
	return midtop;
}
sf::Vector2f Ball::getMidBottom(){
	midbottom = sf::Vector2f(getPosition().x + radius , getPosition().y +2 * radius);
	return midbottom;
}
sf::Vector2f Ball::getMidLeft(){
	midleft = sf::Vector2f(getPosition().x, getPosition().y + radius);
	return midleft;
}
sf::Vector2f Ball::getMidRight(){
	midright = sf::Vector2f(getPosition().x + 2*radius, getPosition().y+radius);
	return midright;
}
void Ball::setPosition(float x, float y) {
	circle.setPosition(x, y);
}
