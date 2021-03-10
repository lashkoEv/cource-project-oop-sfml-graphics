#include "Memento.h"

void Memento::set_type(FigureType s) {
	type = s;
}

FigureType Memento::get_type() {
	return type;
}

void Memento::set_figure(Figure* f) {
	figure = f;
}

Figure* Memento::get_figure() {
	return figure;
}


