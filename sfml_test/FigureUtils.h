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

    void save_state(Figure& figure)
    {
        ofstream fout;
        fout.open(PATH);
        if (!fout.is_open()) {
            cout << "File not opened!" << endl;
        }
        else {
            cout << "File opened!";
            figure.set_memento(memento);
            fout.write((char*)&memento, sizeof(Memento));
        }
        fout.close();
        cout << "Saved!" << endl;
    }

  /*  void load_state(Figure& figure)
    {
        string PATH = "figures.txt";
        ifstream fin;
        fin.open(PATH);
        if (!fin.is_open()) {
            cout << "File not opened!" << endl;
        }
        else {
            cout << "File opened!";

            fin.read((char*)&memento, sizeof(Memento));
            figure.get_memento(memento);
        }
        fin.close();
        cout << "Loaded!" << endl;
    }*/

    Figure* load_state()
    {
        
        ifstream fin;
        fin.open(PATH);
        if (!fin.is_open()) {
            cout << "File not opened!" << endl;
        }
        else {
            cout << "File opened!";
            fin.read((char*)&memento, sizeof(Memento));
            Figure* figure = nullptr;
            if (memento.get_type() == "circle") {
                figure = new Circle();
            }
            if (memento.get_type() == "composite") {
                figure = new Composite();
            }
            if (memento.get_type() == "rectangle") {
                figure = new Rectangle();
            }
            if (memento.get_type() == "square") {
                figure = new Square();
            }
            if (memento.get_type() == "triangle") {
                figure = new Triangle();
            }
            figure->get_memento(memento);
            fin.close();
            cout << "Loaded!" << endl;
            return figure;
        }
    }
};


