#include "FigureUtils.h"

void FigureUtils::save_state(Figure& figure)
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

Figure* FigureUtils::load_state()
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
        if (memento.get_type() == CIRCLE) {
            figure = new Circle();
        }
        if (memento.get_type() == COMPOSITE) {
            figure = new Composite();
        }
        if (memento.get_type() == RECTANGLE) {
            figure = new Rectangle();
        }
        if (memento.get_type() == SQUARE) {
            figure = new Square();
        }
        if (memento.get_type() == TRIANGLE) {
            figure = new Triangle();
        }
        figure->get_memento(memento);
        fin.close();
        cout << "Loaded!" << endl;
        return figure;
    }
}