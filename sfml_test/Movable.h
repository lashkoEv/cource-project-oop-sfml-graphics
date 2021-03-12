#pragma once
class Figure;
class Movable {
protected:
	virtual void move_left(Figure* figure) = 0;
	virtual void move_right(Figure* figure) = 0;
	virtual void move_up(Figure* figure) = 0;
	virtual void move_down(Figure* figure) = 0;
};