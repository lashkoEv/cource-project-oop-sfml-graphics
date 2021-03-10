#include <SFML/Graphics.hpp>	
#include "Scene.h"

void menu(RenderWindow& window);
void show_help(RenderWindow& window);
std::wstring get_help_string();

void menu(RenderWindow& window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture;
	menuTexture1.loadFromFile("resources/111.png");
	menuTexture2.loadFromFile("resources/222.png");
	menuTexture3.loadFromFile("resources/333.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(400, 250);
	menu2.setPosition(430, 350);
	menu3.setPosition(420, 450);

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
				case 2: { 
					show_help(window); 
					while (!Keyboard::isKeyPressed(Keyboard::Escape)); 
					break; 
				}
				case 3: { 
					window.close(); 
					isMenu = false; 
					break; 
				}
			}
		}

		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();
	}
}

void show_help(RenderWindow& window) {
	Font font;
	font.loadFromFile("resources/Fixedsys.ttf");
	Text text("", font, 30);
	text.setStyle(sf::Text::Regular);
	text.setString(get_help_string());
	text.setPosition(0, 0);
	window.draw(text);
	window.display();
}

std::wstring get_help_string()
{
	std::wstring  help;
	help.append(L"\t\t\t\t\t\t\t\t\t   -- Довідка --");
	help.append(L"\nUp - рух об'єкта вгору");
	help.append(L"\nDown - рух об'єкта вниз");
	help.append(L"\nLeft - рух об'єкта вліво");
	help.append(L"\nRight - рух об'єкта вправо");
	help.append(L"\nQ - зміна кольору об'єкта");
	help.append(L"\nW - деформувати об'єкт");
	help.append(L"\nE - повернути об'єкт до початкового стану");
	help.append(L"\nT - рух об'єкта зі слідом/без сліду");
	help.append(L"\nR - рух об'єкта в автоматичному режимі по спіралі");
	help.append(L"\nY - припинити рух в атоматичному режимі");
	help.append(L"\nD - демонстрація роботи деформації під впливом іншого об'єкта");
	help.append(L"\nS - зберегти окрему фігуру або композит фігур на сцену");
	help.append(L"\nC - зберегти фігуру в композит");
	help.append(L"\nBackSpace - вихід з режиму формування композиту");
	help.append(L"\nEscape - закрити вікно");
	help.append(L"\nTab - перейти до наступної фігури");
	help.append(L"\nF1 - додати коло");
	help.append(L"\nF2 - додати прямокутник");
	help.append(L"\nF3 - додати квадрат ");
	help.append(L"\nF4 - додати трикутник");
	help.append(L"\nF5 - перейти до режиму формування композиту з нових фігур");
	help.append(L"\nF6 - перейти до режиму формування композиту з фігур, наявних на сцені");
	help.append(L"\nF7 - клонувати поточну фігуру");
	help.append(L"\nF8 - зберегти фігуру у файл");
	help.append(L"\nF9 - завантажити фігуру із файлу");
	return help;
}

int main()
{
	RenderWindow window(sf::VideoMode(1400, 800), "Main menu");
	menu(window);
	return 0;
}

