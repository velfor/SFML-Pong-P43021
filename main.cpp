#include "SFML/Graphics.hpp"
#include "const.h"
#include "ball.h"

using namespace sf;
int main(){
	RenderWindow window(VideoMode(800, 600), "Test");
	window.setFramerateLimit(FPS);
	//создание игровых объектов
	Ball ball;
	while (window.isOpen()) {
		//обработка событий
		Event event;
		while (window.pollEvent(event))	{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		//update игровых объектов
		ball.update();
		//отрисовка окна
		//1 - очищение окна
		window.clear(Color(50, 50, 50));
		//2 - отрисовка игровых объектов
		window.draw(ball.getShape());
		//3 - отображение
		window.display();
	}
	return 0;
}