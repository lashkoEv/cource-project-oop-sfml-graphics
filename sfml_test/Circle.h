#pragma once
#include "Figure.h"
class Circle :
    public Figure
{
    CircleShape *circle;

public:
    Circle(float r, Color color, int move_x = 0, int move_y = 0) {
        circle = new CircleShape(r);
        circle->setFillColor(color);
        circle->setPosition(move_x, move_y);
        type = "circle";
    }

    Circle() {
        circle = new CircleShape(25);
        circle->setFillColor(Color::Yellow);
        circle->setPosition(0, 0);
        type = "circle";
    }

    ~Circle()
    {
        delete circle;
    }

    void draw(RenderWindow* window) override
    {
        window->draw(*circle); 
    }

    void set_color(Color color) override
    {
        circle->setFillColor(color);
    }

    void move(int move_x = 0, int move_y = 0) override
    {
        circle->move(move_x, move_y);
    }

    void set_position(int move_x = 0, int move_y = 0) override
    {
        circle->setPosition(move_x, move_y);
    }

    int get_position_x() override
    {
        return circle->getPosition().x;
    }

    int get_position_y() override
    {
        return circle->getPosition().y;
    }

    void deformation() override
    {
        circle->setRadius(circle->getRadius() * 1.1);
        if (circle->getRadius() * 2 > VideoMode::getDesktopMode().width ||
            circle->getRadius() * 2 > VideoMode::getDesktopMode().height) {
            set_default();
        }
    }

    void set_default() override
    {
        circle->setFillColor(Color::Yellow);
        circle->setRadius(25);
    }

    FloatRect get_global_bounds() override
    {
        return circle->getGlobalBounds();
    }

    Figure* clone() override
    {
        return new Circle(circle->getRadius(),circle->getFillColor(), circle->getPosition().x, circle->getPosition().y);
    }

    void set_memento(Memento& memento) override
    {
        memento.set_type(get_type());
        memento.set_figure(clone());
    }

    void get_memento(Memento& memento) override
    {
        Circle* new_circle = (Circle*)memento.get_figure();
        circle = new_circle->circle;
    }

    string get_type() override
    {
        return type;
    }
};

