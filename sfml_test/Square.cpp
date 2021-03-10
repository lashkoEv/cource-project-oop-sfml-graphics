#include "Square.h"

Square::Square(float side, Color color, int move_x = 0, int move_y = 0) {
    default_color = color;
    default_size = Vector2f(side, side);
    square = new RectangleShape(default_size);
    square->setFillColor(default_color);
    square->setPosition(move_x, move_y);
    type = SQUARE;
}

Square::Square() {
    default_color = Color::Cyan;
    default_size = Vector2f(50, 50);
    square = new RectangleShape(default_size);
    square->setFillColor(default_color);
    square->setPosition(0, 0);
    type = SQUARE;
}

Square::~Square() {
    delete square;
}

void Square::draw(RenderWindow* window) 
{
    window->draw(*square);
}

void Square::set_color(Color color) 
{
    square->setFillColor(color);
}

void Square::move(int move_x = 0, int move_y = 0) 
{
    square->move(move_x, move_y);
}

void Square::set_position(int move_x = 0, int move_y = 0) 
{
    square->setPosition(move_x, move_y);
}

int Square::get_position_x() 
{
    return square->getPosition().x;
}

int Square::get_position_y() 
{
    return square->getPosition().y;
}

void Square::deformation() 
{
    square->setSize(Vector2f(square->getSize().x * 1.1, square->getSize().y * 1.1));
    if (square->getSize().x > VideoMode::getDesktopMode().width ||
        square->getSize().x > VideoMode::getDesktopMode().height ||
        square->getSize().y > VideoMode::getDesktopMode().width ||
        square->getSize().y > VideoMode::getDesktopMode().height) {
        set_default();
    }
}

void Square::set_default() 
{
    square->setFillColor(default_color);
    square->setSize(default_size);
}

FloatRect Square::get_global_bounds() 
{
    return square->getGlobalBounds();
}

Figure* Square::clone() 
{
    return new Square(square->getSize().x, square->getFillColor(), square->getPosition().x, square->getPosition().y);
}

void Square::set_memento(Memento& memento) 
{
    memento.set_type(get_type());
    memento.set_figure(clone());
}

void Square::get_memento(Memento& memento) 
{
    Square* new_square = (Square*)memento.get_figure();
    square = new_square->square;
}

FigureType Square::get_type()
{
    return type;
}

