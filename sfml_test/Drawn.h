#pragma once
class Figure;
class Drawn {
protected:
	bool is_trace;

	virtual void display() = 0;
	virtual void draw(Figure* figure) = 0;
	virtual void draw() = 0;
	virtual void change_trace() = 0;
};
