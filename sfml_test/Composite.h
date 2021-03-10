#pragma once
#include <iostream>
#include <vector>
#include "Figure.h"
using namespace std;
class Composite : public Figure
{  
    vector<Figure*> figures;

public:

    Composite();
    Composite(Composite* tmp);
    ~Composite();
    void draw(RenderWindow* window) override;
    void add(Figure* figure);
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

