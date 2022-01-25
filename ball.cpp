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
void Ball::update() {
	circle.move(speedx, speedy);
	if (circle.getPosition().x <= 0) {
		speedx = -speedx;
	}
	if (circle.getPosition().x >= WINDOW_WIDTH - 2*radius) {
		speedx = -speedx;
	}
	if (circle.getPosition().y <= 0 ||
		circle.getPosition().y >= WINDOW_HEIGHT - 2 * radius) {
		speedy = -speedy;
	}
}