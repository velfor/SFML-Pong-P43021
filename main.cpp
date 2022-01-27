#include "SFML/Graphics.hpp"
#include "const.h"
#include "ball.h"
#include "left_bat.h"
#include "right_bat.h"
#include "text.h"

using namespace sf;
int main(){
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Test");
	window.setFramerateLimit(FPS);
	//создание игровых объектов
	Ball ball;
	LeftBat left_bat(bat_offset, WINDOW_HEIGHT/2 - bat_half_height);
	RightBat right_bat(
		WINDOW_WIDTH - bat_offset - bat_width, 
		WINDOW_HEIGHT / 2 - bat_half_height
	);
	TextObj left_score("",WINDOW_WIDTH/5, 20);
	TextObj right_score("", 4*WINDOW_WIDTH/5, 20);
	while (window.isOpen()) {
		//обработка событий
		Event event;
		while (window.pollEvent(event))	{
			// ѕользователь нажал на Ђкрестикї и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		//update игровых объектов
		ball.update();
		left_bat.update();
		right_bat.update();
		left_score.update(std::to_string(ball.getLeftScore()));
		right_score.update(std::to_string(ball.getRightScore()));
		//проверка столкновени€ м€ча и левой ракетки
		if (ball.getHitBox().intersects(left_bat.getHitBox())) {
			//ball.setSpeedx(-ball.getSpeedx());
			ball.reboundX();
		}
		//проверка столкновени€ м€ча и правой ракетки
		if (ball.getHitBox().intersects(right_bat.getHitBox())) {
			//ball.setSpeedx(-ball.getSpeedx());
			ball.reboundX();
		}
		//отрисовка окна
		//1 - очищение окна
		window.clear(Color(50, 50, 50));
		//2 - отрисовка игровых объектов
		window.draw(ball.getShape());
		window.draw(left_bat.getShape());
		window.draw(right_bat.getShape());
		window.draw(left_score.getText());
		window.draw(right_score.getText());
		//3 - отображение
		window.display();
	}
	return 0;
}