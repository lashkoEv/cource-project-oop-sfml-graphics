#pragma once
#include "Scene.h"

const int ITEM_COUNT = 3;

class MainMenu
{
	RenderWindow* main_window;
	Texture menu_item_texture[ITEM_COUNT];
	Sprite menu_item[ITEM_COUNT];

	bool prodess_item(int current_item);
	void check_select_item(int& current_item);
	void init_unselect();
	void run_program();
	void show_help();
	std::wstring get_help_string();

public:
	MainMenu();
	~MainMenu();
	void show_menu();
};


