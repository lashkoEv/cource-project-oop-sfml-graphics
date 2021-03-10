#include "Circle.h"

Circle::Circle(float r, Color color, int move_x = 0, int move_y = 0) 
{
    default_color = color;
    default_radius = r;
    circle = new CircleShape(default_radius);
    circle->setFillColor(default_color);
    circle->setPosition(move_x, move_y);
    type = CIRCLE;
}

Circle::Circle() {
    default_color = Color::Yellow;
    default_radius = 25;
    circle = new CircleShape(default_radius);
    circle->setFillColor(default_color);
    circle->setPosition(0, 0);
    type = CIRCLE;
}

Circle::~Circle()
{
    delete circle;
}

void Circle::draw(RenderWindow* window)
{
    window->draw(*circle);
}

void Circle::set_color(Color color) 
{
    circle->setFillColor(color);
}

void Circle::move(int move_x = 0, int move_y = 0) 
{
    circle->move(move_x, move_y);
}

void Circle::set_position(int move_x = 0, int move_y = 0) 
{
    circle->setPosition(move_x, move_y);
}

int Circle::get_position_x() 
{
    return circle->getPosition().x;
}

int Circle::get_position_y() 
{
    return circle->getPosition().y;
}

void Circle::deformation() 
{
    circle->setRadius(circle->getRadius() * 1.1);
    if (circle->getRadius() * 2 > VideoMode::getDesktopMode().width ||
        circle->getRadius() * 2 > VideoMode::getDesktopMode().height) {
        set_default();
    }
}

void Circle::set_default() 
{
    circle->setFillColor(default_color);
    circle->setRadius(default_radius);
}

FloatRect Circle::get_global_bounds() 
{
    return circle->getLocalBounds();
}

Figure* Circle::clone() 
{
    return new Circle(circle->getRadius(), circle->getFillColor(), circle->getPosition().x, circle->getPosition().y);
}

void Circle::set_memento(Memento& memento) 
{
    memento.set_type(get_type());
    memento.set_figure(clone());
}

void Circle::get_memento(Memento& memento) 
{
    Circle* new_circle = (Circle*)memento.get_figure();
    circle = new_circle->circle;
}

FigureType Circle::get_type()
{
    return type;
}