#pragma once
#include "Figure.h"
class Rectangle :
    public Figure
{
    RectangleShape* rectangle;

public:
    Rectangle(float x, float y, Color color, int move_x = 0, int move_y = 0) {
        rectangle = new RectangleShape(Vector2f(x, y));
        rectangle->setFillColor(color);
        rectangle->setPosition(move_x, move_y);
        type = "rectangle";
    }

    Rectangle() {
        rectangle = new RectangleShape(Vector2f(50, 100));
        rectangle->setFillColor(Color::Blue);
        rectangle->setPosition(0, 0);
        type = "rectangle";
    }

    ~Rectangle() {
        delete rectangle;
    }

    void draw(RenderWindow *window) override
    {
        window->draw(*rectangle); 
    }

    void set_color(Color color) override
    {
        rectangle->setFillColor(color);
    }

    void move(int move_x = 0, int move_y = 0) override
    {
        rectangle->move(move_x, move_y);
    }

    void set_position(int move_x = 0, int move_y = 0) override
    {
        rectangle->setPosition(move_x, move_y);
    }

    int get_position_x() override
    {
        return rectangle->getPosition().x;
    }

    int get_position_y() override
    {
        return rectangle->getPosition().y;
    }

    void deformation() override
    {
        rectangle->setSize(Vector2f(rectangle->getSize().x * 1.1, rectangle->getSize().y * 1.1));
        if (rectangle->getSize().x > VideoMode::getDesktopMode().width ||
            rectangle->getSize().x > VideoMode::getDesktopMode().height ||
            rectangle->getSize().y > VideoMode::getDesktopMode().width ||
            rectangle->getSize().y > VideoMode::getDesktopMode().height) {
            set_default();
        }
    }

    void set_default() override
    {
        rectangle->setFillColor(Color::Blue);
        rectangle->setSize(Vector2f(50,100));
    }

    FloatRect get_global_bounds() override
    {
        return rectangle->getGlobalBounds();
    }

    Figure* clone() override
    {
        return new Rectangle(rectangle->getSize().x, rectangle->getSize().y, rectangle->getFillColor(), rectangle->getPosition().x, rectangle->getPosition().y);
    }

    void set_memento(Memento& memento) override
    {
        memento.set_type(get_type());
        memento.set_figure(clone());
    }

    void get_memento(Memento& memento) override
    {
        Rectangle* new_rectangle = (Rectangle*)memento.get_figure();
        rectangle = new_rectangle->rectangle;
    }

    string get_type() override
    {
        return type;
    }
};

