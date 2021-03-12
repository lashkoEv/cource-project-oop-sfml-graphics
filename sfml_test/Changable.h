#pragma once
class Figure;
class Changable {
	virtual void change_color(Figure* figure) = 0;
	virtual void deformate(Figure* figure) = 0;
	virtual void set_default(Figure* figure) = 0;
};