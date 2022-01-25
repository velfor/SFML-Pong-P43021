#include "SFML/Graphics.hpp"
#include "const.h"
#include "ball.h"

using namespace sf;
int main(){
	RenderWindow window(VideoMode(800, 600), "Test");
	window.setFramerateLimit(FPS);
	//�������� ������� ��������
	Ball ball;
	while (window.isOpen()) {
		//��������� �������
		Event event;
		while (window.pollEvent(event))	{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		//update ������� ��������
		ball.update();
		//��������� ����
		//1 - �������� ����
		window.clear(Color(50, 50, 50));
		//2 - ��������� ������� ��������
		window.draw(ball.getShape());
		//3 - �����������
		window.display();
	}
	return 0;
}