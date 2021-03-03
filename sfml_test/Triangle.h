#pragma once
#include "Figure.h"
class Triangle :
    public Figure
{
    CircleShape *triangle;

public:
    Triangle(float height, Color color, int move_x = 0, int move_y = 0) {
        triangle = new CircleShape(height, 3);
        triangle->setFillColor(color);
        triangle->setPosition(move_x, move_y);
        type = "triangle";
    }

    Triangle() {
        triangle = new CircleShape(25, 3);
        triangle->setFillColor(Color::Green);
        triangle->setPosition(0, 0);
    }

    ~Triangle() {
        delete triangle;
    }

    void draw(RenderWindow* window) override
    {
        window->draw(*triangle);
    }

    void set_color(Color color) override
    {
        triangle->setFillColor(color);
    }

    void move(int move_x = 0, int move_y = 0) override
    {
        triangle->move(move_x, move_y);
    }

    void set_position(int move_x = 0, int move_y = 0) override
    {
        triangle->setPosition(move_x, move_y);
    }

    int get_position_x() override
    {
        return triangle->getPosition().x;
    }

    int get_position_y() override
    {
        return triangle->getPosition().y;
    }

    void deformation() override
    {
        triangle->setRadius(triangle->getRadius() * 1.1);
        if (triangle->getRadius() * 2 > VideoMode::getDesktopMode().width ||
            triangle->getRadius() * 2 > VideoMode::getDesktopMode().height) {
            set_default();
        }
    }

    void set_default() override
    {
        triangle->setFillColor(Color::Green);
        triangle->setRadius(25);
    }

    FloatRect get_global_bounds() override
    {
        return triangle->getGlobalBounds();
    }

    Figure* clone() override
    {
        return new Triangle(triangle->getRadius(), triangle->getFillColor(), triangle->getPosition().x, triangle->getPosition().y);
    }

    void set_memento(Memento& memento) override
    {
        memento.set_type(get_type());
        memento.set_figure(clone());
    }

    void get_memento(Memento& memento) override
    {
        Triangle* new_triangle = (Triangle*)memento.get_figure();
        triangle = new_triangle->triangle;
    }

    string get_type() override
    {
        return type;
    }
};

