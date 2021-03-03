#pragma once
#include <iostream>
#include <vector>
#include "Figure.h"
using namespace std;
class Composite : public Figure
{  
    vector<Figure*> figures;
public:
    Composite()
    {
        type = "composite";
    }

    Composite(Composite* tmp)
    {
        for (auto& temp : tmp->figures)
        {
            figures.push_back(temp);
        }
        type = "composite";
    }

    ~Composite()
    {}

    void draw(RenderWindow* window) override
    {
        for (auto& temp : figures)
        {
            temp->draw(window);
        }
    }
   
    void add(Figure* figure)
    {
        figures.push_back(figure);
        cout << "add " << figure->get_type() << " to composite" << endl;
    }

    void set_color(Color color) override
    {
        for (auto& temp : figures)
        {
            temp->set_color(color);
        }
    }

    void move(int move_x = 0, int move_y = 0) override
    {
        for (auto& temp : figures)
        {
            temp->move(move_x, move_y);
        }
    }

    void set_position(int move_x = 0, int move_y = 0) override
    {
        for (auto& temp : figures)
        {
            temp->set_position(move_x, move_y);
        }
    }

    int get_position_x() override
    {
        return figures[0]->get_position_x();
    }

    int get_position_y() override
    {
        return figures[0]->get_position_y();
    }

    void deformation() override
    {
        for (auto& temp : figures)
        {
            temp->deformation();
        }
    }

    void set_default() override
    {
        for (auto& temp : figures)
        {
            temp->set_default();
        }
    }

    FloatRect get_global_bounds() override
    {
        return figures[0]->get_global_bounds();
    }

    Figure* clone() override
    {
        return new Composite(this);
    }

    void set_memento(Memento& memento) override
    {
        memento.set_type(get_type());
        memento.set_figure(clone());
    }

    void get_memento(Memento& memento) override
    {
        Composite* new_composite = (Composite*)memento.get_figure();
        figures = new_composite->figures;
    }

    string get_type() override
    {
        return type;
    }
};

