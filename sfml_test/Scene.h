#pragma once	
#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Composite.h"
#include "FigureUtils.h"
#include "Movable.h"
#include "Changable.h"
#include "Drawn.h"
#include <iostream>
#include <vector>
using namespace std;

const Vector2f CURRENT_WINDOW(VideoMode::getDesktopMode().width - 100, VideoMode::getDesktopMode().height - 100);
const int DX = 10;

class Scene : Movable, Changable, Drawn
{
	ContextSettings* settings;
	RenderWindow* window;
	int pointer;
	vector<Figure*> figures;
	bool mode;

	Scene();
public:
	
	static Scene* get_instance() {
		static Scene instance;
		return &instance;
	}

	~Scene();
	void init();
	Figure& get_figure(int index);
	void new_window();
	void process_global(Figure* figure, Event event);
	void process_figure(Figure* figure, Event event);
	void save_to_file(Figure* figure);
	void load_from_file();
	void demonstrate_deformation();
	void clone_figure(Figure* figure);
	void composite_from_existing_figures();
	void save_to_composite(Figure* figure, Composite* composite);
	void composite_formation();
	void mode_selection(Event event);
	void add_figure(Composite* composite, Keyboard::Key key);
	void save_figure(Figure* figure);
	void change_pointer();
	void change_trace() override;
	void move_left(Figure* figure) override;
	void move_right(Figure* figure) override;
	void move_up(Figure* figure) override;
	void move_down(Figure* figure) override;
	void change_color(Figure* figure) override;
	void deformate(Figure* figure) override;
	void set_default(Figure* figure) override;
	void display() override;
	RenderWindow& get_window();
	void draw(Figure* figure) override;
	void draw() override;
	void auto_mode(Figure* figure);
};
