#include "SFML/Graphics.hpp"
#include "const.h"
#include "ball.h"
#include "left_bat.h"
#include "right_bat.h"
#include "text.h"
enum GameState {INTRO, PLAY, GAME_OVER};
using namespace sf;
int main(){
	GameState game_state = INTRO;
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Test");
	window.setFramerateLimit(FPS);
	//создание игровых объектов
	Ball ball;
	LeftBat left_bat(bat_offset, WINDOW_HEIGHT/2 - bat_half_height);
	RightBat right_bat(
		WINDOW_WIDTH - bat_offset - bat_width, 
		WINDOW_HEIGHT / 2 - bat_half_height
	);
	TextObj left_score("",WINDOW_WIDTH/5, 20,32);
	TextObj right_score("", 4*WINDOW_WIDTH/5, 20,32);
	TextObj intro("", WINDOW_WIDTH / 2 - 160, WINDOW_HEIGHT / 2 - 100, 144);
	while (window.isOpen()) {
		//обработка событий
		Event event;
		while (window.pollEvent(event))	{
			// ѕользователь нажал на Ђкрестикї и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Space) {
					game_state = PLAY;
				}
			}
		}
		switch (game_state)
		{
		case INTRO:
			intro.update("PONG");
			window.clear(Color(50, 50, 50));
			window.draw(intro.getText());
			window.display();
			break;
		case PLAY:
			//update игровых объектов
			ball.update();
			left_bat.update();
			right_bat.update();
			left_score.update(std::to_string(ball.getLeftScore()));
			right_score.update(std::to_string(ball.getRightScore()));
			//проверка столкновени€ м€ча и левой ракетки
			if (ball.getHitBox().intersects(left_bat.getHitBox())) {
				//c правой границей ракетки
				if (left_bat.getHitBox().contains(ball.getMidLeft())) {
					//выталкиваем м€ч из ракетки
					ball.setPosition(left_bat.getPosition().x + left_bat.getWidth(),
						ball.getPosition().y);
					//мен€ем направление м€ча
					ball.reboundX();
				}
				//с верхней границей
				if (left_bat.getHitBox().contains(ball.getMidBottom())) {
					ball.setPosition(ball.getPosition().x,
						left_bat.getPosition().y - 2*ball.getRadius());
					ball.reboundY();
				}
				//c нижней границей
				if (left_bat.getHitBox().contains(ball.getMidTop())) {
					ball.setPosition(ball.getPosition().x, 
						left_bat.getPosition().y + left_bat.getHeight());
					ball.reboundY();
				}
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
			break;
		case GAME_OVER:

			break;
		default:
			break;
		}
		
	}
	return 0;
}