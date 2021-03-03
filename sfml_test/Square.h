#pragma once
#include "Figure.h"
class Square :
    public Figure
{
    RectangleShape* square;

public:
    Square(float side, Color color, int move_x = 0, int move_y = 0) {
        square = new RectangleShape(Vector2f(side, side));
        square->setFillColor(color);
        square->setPosition(move_x, move_y);
        type = "square";
    }

    Square() {
        square = new RectangleShape(Vector2f(50, 50));
        square->setFillColor(Color::Cyan);
        square->setPosition(0, 0);
        type = "square";
    }

    ~Square() {
        delete square;
    }

    void draw(RenderWindow* window) override
    {
        window->draw(*square);
    }

    void set_color(Color color) override
    {
        square->setFillColor(color);
    }

    void move(int move_x = 0, int move_y = 0) override
    {
        square->move(move_x, move_y);
    }

    void set_position(int move_x = 0, int move_y = 0) override
    {
        square->setPosition(move_x, move_y);
    }

    int get_position_x() override
    {
        return square->getPosition().x;
    }

    int get_position_y() override
    {
        return square->getPosition().y;
    }

    void deformation() override
    {
        square->setSize(Vector2f(square->getSize().x * 1.1, square->getSize().y * 1.1));
        if (square->getSize().x > VideoMode::getDesktopMode().width ||
            square->getSize().x > VideoMode::getDesktopMode().height ||
            square->getSize().y > VideoMode::getDesktopMode().width ||
            square->getSize().y > VideoMode::getDesktopMode().height) {
            set_default();
        }
    }

    void set_default() override
    {
        square->setFillColor(Color::Cyan);
        square->setSize(Vector2f(50, 50));
    }

    FloatRect get_global_bounds() override
    {
        return square->getGlobalBounds();
    }

    Figure* clone() override
    {
        return new Square(square->getSize().x, square->getFillColor(), square->getPosition().x, square->getPosition().y);
    }

    void set_memento(Memento& memento) override
    {
        memento.set_type(get_type());
        memento.set_figure(clone());
    }

    void get_memento(Memento& memento) override
    {
        Square* new_square = (Square*)memento.get_figure();
        square = new_square->square;
    }

    string get_type() override
    {
        return type;
    }
};

