#pragma once
#include "Figure.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class Figure;
class Memento
{
	friend class Figure;
	string type;
	Figure* figure;

public:

	void set_type(string s) {
		type = s;
	}

	string get_type() {
		return type;
	}

	void set_figure(Figure* f) {
		figure = f;
	}

	Figure* get_figure() {
		return figure;
	}
};


