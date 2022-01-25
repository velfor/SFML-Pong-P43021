#pragma once
#include "bat.h"
#include "const.h"

class LeftBat : public Bat {
public:
	LeftBat(float startx, float starty) : Bat(startx, starty) {}
	void update() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			rect.move(0.f, -speedy);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			rect.move(0.f, speedy);
		}
		float currx = rect.getPosition().x;
		if (rect.getPosition().y <= 0) {
			rect.setPosition(currx, 0);
		}
		if (rect.getPosition().y >= WINDOW_HEIGHT - height) {
			rect.setPosition(currx, WINDOW_HEIGHT - height);
		}
	}
};
