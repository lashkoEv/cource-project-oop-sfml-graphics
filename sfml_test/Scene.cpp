#include "Scene.h"

Scene::Scene()
{
	pointer = 0;
	mode = false;
	init();
	is_trace = false;
	settings = new ContextSettings;
	settings->antialiasingLevel = 8;
	window = new RenderWindow(VideoMode(CURRENT_WINDOW.x, CURRENT_WINDOW.y), "Application", Style::Default, *settings);
}

Scene::~Scene()
{
	delete settings;
	delete window;
}

void Scene::init()
{
	Composite* c = new Composite();
	c->add(new Rectangle(70.0f, 100.0f, Color::Blue, 10, 20));
	c->add(new Square(50.0f, Color::Yellow, 550, 20));
	Composite* composite = new Composite();
	composite->add(new Circle(40.0f, Color::Cyan, 300, 20));
	composite->add(c);
	Composite* c2 = new Composite();
	c2->add(new Triangle(70.0f, Color::Green, 180, 20));
	composite->add(c2);
	figures.push_back(composite);
	Circle* circle = new Circle();
	figures.push_back(circle);
	figures.push_back(circle->clone());
	change_color(circle);
	deformate(circle);
	figures.push_back(c->clone());

	FigureUtils f;
	Square* square = new Square();
	f.save_state(*square);
	change_color(square);
	figures.push_back(square);
	figures.push_back(f.load_state());
	Composite* cc = new Composite();
	cc->add(new Rectangle(50.0f, 100.0f, Color::Blue, 10, 20));
	cc->add(new Square(50.0f, Color::Yellow, 550, 20));
	f.save_state(*cc);
	figures.push_back(f.load_state());
}

Figure& Scene::get_figure(int index) {
	return *figures[index];
}

void Scene::new_window() {
	window = new RenderWindow(VideoMode(CURRENT_WINDOW.x, CURRENT_WINDOW.y), "Application", Style::Default, *settings);
}

void Scene::process_global(Figure* figure, Event event)
{
	process_figure(figure, event);
	if (event.type == Event::Closed) { get_window().close(); }
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
		case sf::Keyboard::Escape: { get_window().close(); break; }
		case sf::Keyboard::BackSpace: { mode = false; break; }
		case sf::Keyboard::Tab: { change_pointer(); break; }
		case sf::Keyboard::F1: case sf::Keyboard::F2: case sf::Keyboard::F3:
		case sf::Keyboard::F4: { add_figure((Composite*)figure, event.key.code); break; }
		case sf::Keyboard::S: { save_figure(figure); break; }
		case sf::Keyboard::F5: { composite_formation(); break; }
		case sf::Keyboard::F6: { composite_from_existing_figures(); break; }
		case sf::Keyboard::D: { demonstrate_deformation(); break; }
		case sf::Keyboard::F7: { clone_figure(figure); break; }
		case sf::Keyboard::F8: { save_to_file(figure); break; }
		case sf::Keyboard::F9: { load_from_file(); break; }
		}
	}
}

void Scene::process_figure(Figure* figure, Event event)
{
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
		case sf::Keyboard::Left: { move_left(figure); break; }
		case sf::Keyboard::Right: { move_right(figure); break; }
		case sf::Keyboard::Up: { move_up(figure); break; }
		case sf::Keyboard::Down: { move_down(figure); break; }
		case sf::Keyboard::Q: { change_color(figure); break; }
		case sf::Keyboard::W: { deformate(figure); break; }
		case sf::Keyboard::E: { set_default(figure); break; }
		case sf::Keyboard::T: { change_trace(); break; }
		case sf::Keyboard::R: { auto_mode(figure); break; }
		}
	}
}

void Scene::save_to_file(Figure* figure) {
	if (figure != nullptr) {
		FigureUtils f;
		f.save_state(*(figure->clone()));
	}
}

void Scene::load_from_file() {
	FigureUtils f;
	figures.push_back((f.load_state())->clone());
}

void Scene::demonstrate_deformation()
{
	mode = true;
	Circle* anchor = new Circle(100, Color::Color(204, 174, 238), CURRENT_WINDOW.x / 2 - 200, CURRENT_WINDOW.y / 2 - 200);
	Rectangle* rectangle = new Rectangle();
	bool is_deformate = false;
	bool check_position = false;
	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			process_global(rectangle, event);
			if (anchor->get_global_bounds().intersects(rectangle->get_global_bounds())) {
				if (!is_deformate) {
					rectangle->deformation();
					is_deformate = true;
				}
			}
			else {
				is_deformate = false;
			}
			if (Keyboard::isKeyPressed(Keyboard::BackSpace)) { return; }
		}
		window->clear();
		anchor->draw(window);
		rectangle->draw(window);
		display();
	}
}

void Scene::clone_figure(Figure* figure) {
	if (figure != nullptr) {
		figures.push_back(figure->clone());
	}
}

void Scene::composite_from_existing_figures() {
	mode = true;
	int iterator = 0;
	Composite* composite = new Composite();
	Figure* shape = figures[iterator];

	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				process_figure(shape, event);
				if (Keyboard::isKeyPressed(Keyboard::BackSpace)) { mode = false; return; }
				if (Keyboard::isKeyPressed(Keyboard::Tab)) {
					if (iterator < figures.size() - 1) {
						shape = figures[++iterator];
					}
					else {
						iterator = 0;
						shape = figures[iterator];
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::C)) {
					save_to_composite(shape->clone(), composite);
					figures.erase(figures.begin() + iterator);
				}
				if (Keyboard::isKeyPressed(Keyboard::S)) { save_figure(composite->clone()); }
			}
		}
		draw(shape);
		display();
	}
}

void Scene::save_to_composite(Figure* figure, Composite* composite)
{
	if (composite != nullptr) {
		composite->add(figure);
		mode = false;
	}
}

void Scene::composite_formation()
{
	mode = true;
	Composite* composite = new Composite();

	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			process_global(composite, event);
			if (Keyboard::isKeyPressed(Keyboard::BackSpace)) { return; }
		}
		draw(composite);
		display();
	}
}

void Scene::mode_selection(Event event)
{
	if (!mode) {
		process_global(figures[pointer], event);
	}
}

void Scene::add_figure(Composite* composite, Keyboard::Key key)
{
	mode = true;
	Figure* figure = nullptr;

	switch (key) {
	case sf::Keyboard::F1: { figure = new Circle(); break; }
	case sf::Keyboard::F2: { figure = new Rectangle(); break; }
	case sf::Keyboard::F3: { figure = new Square(); break; }
	case sf::Keyboard::F4: { figure = new Triangle(); break; }
	}

	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			process_global(figure, event);
			if (Keyboard::isKeyPressed(Keyboard::C) && composite != nullptr) { save_to_composite(figure, composite); return; }
			if (Keyboard::isKeyPressed(Keyboard::BackSpace)) { return; }
		}
		draw(figure);
		display();
	}
}

void Scene::save_figure(Figure* figure)
{
	figures.push_back(figure);
	mode = false;
}

void Scene::change_pointer()
{
	if (pointer < figures.size() - 1) {
		pointer++;
	}
	else {
		pointer = 0;
	}
}

void Scene::change_trace() 
{
	is_trace = !is_trace;
}

void Scene::move_left(Figure* figure)
{
	if (figure->get_position_x() <= 0) {
		figure->move(CURRENT_WINDOW.x - DX, 0);
	}
	else {
		figure->move(-DX, 0);
	}
}

void Scene::move_right(Figure* figure)
{
	if (figure->get_position_x() >= CURRENT_WINDOW.x) {
		figure->move(-CURRENT_WINDOW.x + DX, 0);
	}
	else {
		figure->move(DX, 0);
	}
}

void Scene::move_up(Figure* figure)
{
	if (figure->get_position_y() <= 0) {
		figure->move(0, CURRENT_WINDOW.y - DX);
	}
	else {
		figure->move(0, -DX);
	}
}

void Scene::move_down(Figure* figure)
{
	if (figure->get_position_y() >= CURRENT_WINDOW.y) {
		figure->move(0, -CURRENT_WINDOW.y + DX);
	}
	else {
		figure->move(0, DX);
	}
}

void Scene::change_color(Figure* figure) 
{
	figure->set_color(Color::Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));
}

void Scene::deformate(Figure* figure) 
{
	figure->deformation();
}

void Scene::set_default(Figure* figure) 
{
	figure->set_default();
}

void Scene::display() 
{
	window->display();
}

RenderWindow& Scene::get_window()
{
	return *window;
}

void Scene::draw(Figure* figure)
{
	if (!is_trace) {
		window->clear();
	}
	figure->draw(window);
}

void Scene::draw()
{
	if (!is_trace) {
		window->clear();
	}
	figures[pointer]->draw(&get_window());
}

void Scene::auto_mode(Figure* figure)
{
	int seg_count = 50;
	float angle;
	double x, y;
	int r = 50;
	while (true) {
		for (int j = 0; j < seg_count; j++)
		{
			angle = (2.0f * 3.14f) * (float(j) / float(seg_count));
			x = r * cos(angle);
			y = r * sin(angle);
			figure->move(x, y);
			move_right(figure);
			draw(figure);
			display();
			sleep(milliseconds(30));
			if (Keyboard::isKeyPressed(Keyboard::Y)) {
				return;
			}
		}
	}
}

