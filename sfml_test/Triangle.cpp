#include "Triangle.h"

Triangle::Triangle(float height, Color color, int move_x = 0, int move_y = 0) {
    default_color = color;
    default_height = height; 
    triangle = new CircleShape(default_height, 3);
    triangle->setFillColor(default_color);
    triangle->setPosition(move_x, move_y);
    type = "triangle";
    
}

Triangle::Triangle() {
    default_color = Color::Green;
    default_height = 25;
    triangle = new CircleShape(default_height, 3);
    triangle->setFillColor(default_color);
    triangle->setPosition(0, 0);
}

Triangle::~Triangle() {
    delete triangle;
}

void Triangle::draw(RenderWindow* window) 
{
    window->draw(*triangle);
}

void Triangle::set_color(Color color) 
{
    triangle->setFillColor(color);
}

void Triangle::move(int move_x = 0, int move_y = 0) 
{
    triangle->move(move_x, move_y);
}

void Triangle::set_position(int move_x = 0, int move_y = 0) 
{
    triangle->setPosition(move_x, move_y);
}

int Triangle::get_position_x() 
{
    return triangle->getPosition().x;
}

int Triangle::get_position_y() 
{
    return triangle->getPosition().y;
}

void Triangle::deformation() 
{
    triangle->setRadius(triangle->getRadius() * 1.1);
    if (triangle->getRadius() * 2 > VideoMode::getDesktopMode().width ||
        triangle->getRadius() * 2 > VideoMode::getDesktopMode().height) {
        set_default();
    }
}

void Triangle::set_default() 
{
    triangle->setFillColor(default_color);
    triangle->setRadius(default_height);
}

FloatRect Triangle::get_global_bounds() 
{
    return triangle->getGlobalBounds();
}

Figure* Triangle::clone() 
{
    return new Triangle(triangle->getRadius(), triangle->getFillColor(), triangle->getPosition().x, triangle->getPosition().y);
}

void Triangle::set_memento(Memento& memento) 
{
    memento.set_type(get_type());
    memento.set_figure(clone());
}

void Triangle::get_memento(Memento& memento) 
{
    Triangle* new_triangle = (Triangle*)memento.get_figure();
    triangle = new_triangle->triangle;
}

string Triangle::get_type() 
{
    return type;
}