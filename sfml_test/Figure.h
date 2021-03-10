#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Memento.h"
#include "FigureType.h"
using namespace sf;
using namespace std;
class Memento;
class Figure 
{
protected:
	FigureType type;
public:
	virtual void draw(RenderWindow *window) = 0;
	virtual void set_color(Color color) = 0;
	virtual void move(int move_x, int move_y) = 0;
	virtual void set_position(int move_x, int move_y) = 0;
	virtual int get_position_x() = 0;
	virtual int get_position_y() = 0;
	virtual void deformation() = 0;
	virtual void set_default() = 0;
	virtual FloatRect get_global_bounds() = 0;
	virtual Figure* clone() = 0;
	virtual void set_memento(Memento& memento) = 0;
	virtual void get_memento(Memento& memento) = 0;
	virtual FigureType get_type() = 0;
};


