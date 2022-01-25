#include "bat.h"
#include "const.h"

Bat::Bat(float startx, float starty) {
	rect.setSize(sf::Vector2f(width,height));
	rect.setPosition(startx, starty);
	rect.setFillColor(sf::Color(255, 250, 205));
}
sf::RectangleShape Bat::getShape() { return rect; }
float Bat::getWidth() { return width; }
float Bat::getHeight() { return height; }
float Bat::getSpeedy() { return speedy; }
sf::Vector2f Bat::getPosition() { return rect.getPosition(); }
void Bat::setPosition(float x, float y) { rect.setPosition(x, y); }