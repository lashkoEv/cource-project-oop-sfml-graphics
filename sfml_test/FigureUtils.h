#pragma once
#include <fstream>
#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Composite.h"

const string PATH = "figures.txt";

class FigureUtils
{
    Memento memento;

public:

    void save_state(Figure& figure);
    Figure* load_state();
};


