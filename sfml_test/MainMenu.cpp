#include "MainMenu.h"

MainMenu::MainMenu() {
	main_window = new RenderWindow(sf::VideoMode(1400, 800), "Main menu");
	menu_item_texture[0].loadFromFile("resources/111.png");
	menu_item_texture[1].loadFromFile("resources/222.png");
	menu_item_texture[2].loadFromFile("resources/333.png");
	for (int i = 0; i < ITEM_COUNT; i++)
	{
		menu_item[i].setTexture(menu_item_texture[i]);
	}
	menu_item[0].setPosition(400, 250);
	menu_item[1].setPosition(430, 350);
	menu_item[2].setPosition(420, 450);
}

MainMenu::~MainMenu() {
	delete main_window;
}

void MainMenu::show_menu() {
	bool is_opened = true;

	while (is_opened)
	{
		int current_item = 0;
		init_unselect();
		check_select_item(current_item);
		is_opened = prodess_item(current_item);
		for (int i = 0; i < ITEM_COUNT; i++)
		{
			main_window->draw(menu_item[i]);
		}
		main_window->display();
	}
}

bool MainMenu::prodess_item(int current_item) {
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		switch (current_item) {
		case 1: {
			run_program();
			break;
		}
		case 2: {
			show_help();
			while (!Keyboard::isKeyPressed(Keyboard::Escape));
			break;
		}
		case 3: {
			main_window->close();
			return false;
		}
		}
	}
	return true;
}

void MainMenu::check_select_item(int& current_item) {
	if (IntRect(menu_item[0].getPosition().x, menu_item[0].getPosition().y, 600, 50).contains(Mouse::getPosition(*main_window))) {
		menu_item[0].setColor(Color(96, 221, 255));
		current_item = 1;
	}
	if (IntRect(menu_item[1].getPosition().x, menu_item[1].getPosition().y, 500, 50).contains(Mouse::getPosition(*main_window))) {
		menu_item[1].setColor(Color(255, 214, 96));
		current_item = 2;
	}
	if (IntRect(menu_item[2].getPosition().x, menu_item[2].getPosition().y, 550, 50).contains(Mouse::getPosition(*main_window))) {
		menu_item[2].setColor(Color(214, 133, 255));
		current_item = 3;
	}
}
void MainMenu::init_unselect() {
	for (int i = 0; i < ITEM_COUNT; i++)
	{
		menu_item[i].setColor(Color::White);
	}
	main_window->clear(Color(Color::Black));
}

void MainMenu::run_program() {
	Scene* scene = Scene::get_instance();
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
}

void MainMenu::show_help() {
	Font font;
	font.loadFromFile("resources/Fixedsys.ttf");
	Text text("", font, 30);
	text.setStyle(sf::Text::Regular);
	text.setString(get_help_string());
	text.setPosition(0, 0);
	main_window->draw(text);
	main_window->display();
}

std::wstring MainMenu::get_help_string()
{
	std::wstring  help;
	help.append(L"\t\t\t\t\t\t\t\t\t   -- ������ --");
	help.append(L"\nUp - ��� ��'���� �����");
	help.append(L"\nDown - ��� ��'���� ����");
	help.append(L"\nLeft - ��� ��'���� ����");
	help.append(L"\nRight - ��� ��'���� ������");
	help.append(L"\nQ - ���� ������� ��'����");
	help.append(L"\nW - ����������� ��'���");
	help.append(L"\nE - ��������� ��'��� �� ����������� �����");
	help.append(L"\nT - ��� ��'���� � �����/��� ����");
	help.append(L"\nR - ��� ��'���� � ������������� ����� �� �����");
	help.append(L"\nY - ��������� ��� � ������������ �����");
	help.append(L"\nD - ������������ ������ ���������� �� ������� ������ ��'����");
	help.append(L"\nS - �������� ������ ������ ��� �������� ����� �� �����");
	help.append(L"\nC - �������� ������ � ��������");
	help.append(L"\nBackSpace - ����� � ������ ���������� ���������");
	help.append(L"\nEscape - ������� ����");
	help.append(L"\nTab - ������� �� �������� ������");
	help.append(L"\nF1 - ������ ����");
	help.append(L"\nF2 - ������ �����������");
	help.append(L"\nF3 - ������ ������� ");
	help.append(L"\nF4 - ������ ���������");
	help.append(L"\nF5 - ������� �� ������ ���������� ��������� � ����� �����");
	help.append(L"\nF6 - ������� �� ������ ���������� ��������� � �����, ������� �� ����");
	help.append(L"\nF7 - ��������� ������� ������");
	help.append(L"\nF8 - �������� ������ � ����");
	help.append(L"\nF9 - ����������� ������ �� �����");
	return help;
}