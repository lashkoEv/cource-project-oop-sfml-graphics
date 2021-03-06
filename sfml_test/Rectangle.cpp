#include "Rectangle.h"

Rectangle::Rectangle(float x, float y, Color color, int move_x = 0, int move_y = 0) {
    default_color = color;
    default_size = Vector2f(x, y);
    rectangle = new RectangleShape(Vector2f(x, y));
    rectangle->setFillColor(color);
    rectangle->setPosition(move_x, move_y);
    type = "rectangle";
}

Rectangle::Rectangle() {
    default_color = Color::Blue;
    default_size = Vector2f(50, 100);
    rectangle = new RectangleShape(default_size);
    rectangle->setFillColor(default_color);
    rectangle->setPosition(0, 0);
    type = "rectangle";
}

Rectangle::~Rectangle() {
    delete rectangle;
}

void Rectangle::draw(RenderWindow* window) 
{
    window->draw(*rectangle);
}

void Rectangle::set_color(Color color) 
{
    rectangle->setFillColor(color);
}

void Rectangle::move(int move_x = 0, int move_y = 0)
{
    rectangle->move(move_x, move_y);
}

void Rectangle::set_position(int move_x = 0, int move_y = 0) 
{
    rectangle->setPosition(move_x, move_y);
}

int Rectangle::get_position_x() 
{
    return rectangle->getPosition().x;
}

int Rectangle::get_position_y() 
{
    return rectangle->getPosition().y;
}

void Rectangle::deformation() 
{
    rectangle->setSize(Vector2f(rectangle->getSize().x * 1.1, rectangle->getSize().y * 1.1));
    if (rectangle->getSize().x > VideoMode::getDesktopMode().width ||
        rectangle->getSize().x > VideoMode::getDesktopMode().height ||
        rectangle->getSize().y > VideoMode::getDesktopMode().width ||
        rectangle->getSize().y > VideoMode::getDesktopMode().height) {
        set_default();
    }
}

void Rectangle::set_default() 
{
    rectangle->setFillColor(default_color);
    rectangle->setSize(default_size);
}

FloatRect Rectangle::get_global_bounds() 
{
    return rectangle->getGlobalBounds();
}

Figure* Rectangle::clone() 
{
    return new Rectangle(rectangle->getSize().x, rectangle->getSize().y, rectangle->getFillColor(), rectangle->getPosition().x, rectangle->getPosition().y);
}

void Rectangle::set_memento(Memento& memento) 
{
    memento.set_type(get_type());
    memento.set_figure(clone());
}

void Rectangle::get_memento(Memento& memento) 
{
    Rectangle* new_rectangle = (Rectangle*)memento.get_figure();
    rectangle = new_rectangle->rectangle;
}

string Rectangle::get_type() 
{
    return type;
}