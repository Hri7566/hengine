#include "../hengine/ui/Button.hpp"
#include "../hengine/Engine.hpp"
#include "config.hpp"
#include "box.hpp"
#include <raylib.h>
#include <iostream>

void e_load(void);
void e_update(float delta);
void e_draw(void);
void btn_clicked(float delta);

Engine *e;
Button *test_btn;
Box *box;

int main(void) {
	EngineConfig e_config;

	e_config.window_config.size.x = WINDOW_WIDTH;
	e_config.window_config.size.y = WINDOW_HEIGHT;
	e_config.window_config.title = WINDOW_TITLE;

	e = new Engine(e_config, &e_load, &e_update, &e_draw);
	e->start();

	free(box);
	free(test_btn);

	return 0;
}

void e_load(void) {
	test_btn = new Button({64, 64}, {96, 16}, RAYWHITE, GRAY, BLACK);
	test_btn->onClick = btn_clicked;
	test_btn->label = "button";

	box = new Box({64, 96}, {64, 64}, RAYWHITE);
	e->actor_list.add(box);
}

void e_update(float delta) {
	test_btn->update(delta);
}

void e_draw() {
	test_btn->draw();
}

void btn_clicked(float delta) {
	std::cout << "clicked!" << std::endl;
	test_btn->label = "clicked!";

	box->color = GREEN;
}
