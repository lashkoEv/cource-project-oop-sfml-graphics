#pragma once
#include "Figure.h"
#include "FigureType.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class Figure;
class Memento
{
	friend class Figure;
	FigureType type;
	Figure* figure;

public:

	void set_type(FigureType s);
	FigureType get_type();
	void set_figure(Figure* f);
	Figure* get_figure();
};


