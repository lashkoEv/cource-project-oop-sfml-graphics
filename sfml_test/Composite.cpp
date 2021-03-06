#include "Composite.h"

Composite::Composite()
{
    type = "composite";
}

Composite::Composite(Composite* tmp)
{
    for (auto& temp : tmp->figures)
    {
        figures.push_back(temp->clone());
    }
    type = "composite";
}

Composite::~Composite()
{}

void Composite::draw(RenderWindow* window) 
{
    for (auto& temp : figures)
    {
        temp->draw(window);
    }
}

void Composite::add(Figure* figure)
{
    figures.push_back(figure);
    cout << "add " << figure->get_type() << " to composite" << endl;
}

void Composite::set_color(Color color) 
{
    for (auto& temp : figures)
    {
        temp->set_color(color);
    }
}

void Composite::move(int move_x = 0, int move_y = 0)
{
    for (auto& temp : figures)
    {
        temp->move(move_x, move_y);
    }
}

void Composite::set_position(int move_x = 0, int move_y = 0) 
{
    for (auto& temp : figures)
    {
        temp->set_position(move_x, move_y);
    }
}

int Composite::get_position_x()
{
    return figures[0]->get_position_x();
}

int Composite::get_position_y()
{
    return figures[0]->get_position_y();
}

void Composite::deformation()
{
    for (auto& temp : figures)
    {
        temp->deformation();
    }
}

void Composite::set_default()
{
    for (auto& temp : figures)
    {
        temp->set_default();
    }
}

FloatRect Composite::get_global_bounds()
{
    return figures[0]->get_global_bounds();
}

Figure* Composite::clone()
{
    return new Composite(this);
}

void Composite::set_memento(Memento& memento)
{
    memento.set_type(get_type());
    memento.set_figure(clone());
}

void Composite::get_memento(Memento& memento)
{
    Composite* new_composite = (Composite*)memento.get_figure();
    figures = new_composite->figures;
}

string Composite::get_type()
{
    return type;
}