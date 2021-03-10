#pragma once
#include "Figure.h"
class Triangle :
    public Figure
{
    CircleShape *triangle;
    Color default_color;
    float default_height;
public:
    Triangle(float height, Color color, int move_x, int move_y);
    Triangle();
    ~Triangle();
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

