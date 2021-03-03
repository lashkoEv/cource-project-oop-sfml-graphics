#include <SFML/Graphics.hpp>	
#include "Scene.h"


void menu(RenderWindow& window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture;
	menuTexture1.loadFromFile("images/111.png");
	menuTexture2.loadFromFile("images/222.png");
	menuTexture3.loadFromFile("images/333.png");
	aboutTexture.loadFromFile("images/about.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(220, 100);
	menu2.setPosition(250, 200);
	menu3.setPosition(240, 300);

	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(Color::Black));

		if (IntRect(menu1.getPosition().x, menu1.getPosition().y, 600, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color(96, 221, 255)); menuNum = 1; }
		if (IntRect(menu2.getPosition().x, menu2.getPosition().y, 500, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color(255, 214, 96)); menuNum = 2; }
		if (IntRect(menu3.getPosition().x, menu3.getPosition().y, 550, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color(214, 133, 255)); menuNum = 3; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			switch (menuNum) {
			case 1: {
				Scene *scene = Scene::get_instance();
				if (!scene->get_window().isOpen()) {
					scene->new_window();
				}
				while (scene->get_window().isOpen())
				{
					Event event;
					while (scene->get_window().pollEvent(event))
					{
						scene->mode_selection(event);
					}
					scene->draw();
					scene->get_window().display();
				}
				break;
			}
			case 2: { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); break; }
			case 3: { window.close(); isMenu = false; break; }
			}
		}

		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();
	}
}

int main()
{
	RenderWindow window(sf::VideoMode(1000, 500), "Main menu");
	menu(window);
	return 0;
}

