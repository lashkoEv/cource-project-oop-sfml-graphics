#pragma once
#include "Figure.h"
class Rectangle :
    public Figure
{
    RectangleShape* rectangle;
    Color default_color;
    Vector2f default_size;
public:
    Rectangle(float x, float y, Color color, int move_x, int move_y);
    Rectangle();
    ~Rectangle();
    void draw(RenderWindow* window) override;
    void set_color(Color color) override;
    void move(int move_x, int move_y) override;
    void set_position(int move_x, int move_y) override;
    int get_position_x() override;
    int get_position_y() override;
    void deformation() override;
    void set_default() override;
    FloatRect get_global_bounds() override;
    Figure* clone() override;
    void set_memento(Memento& memento) override;
    void get_memento(Memento& memento) override;
    FigureType get_type() override;
};

