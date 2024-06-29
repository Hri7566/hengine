#include "../hengine/ui/Button.hpp"
#include "../hengine/Engine.hpp"
#include "config.hpp"
#include <raylib.h>
#include <iostream>

void e_load(void);
void e_update(float delta);
void e_draw(void);
void btn_clicked(float delta);

Engine *e;
Button *btnTest;

int main(void) {
	EngineConfig e_config;

	e_config.window_config.size.x = WINDOW_WIDTH;
	e_config.window_config.size.y = WINDOW_HEIGHT;
	e_config.window_config.title = WINDOW_TITLE;

	e = new Engine(e_config, &e_load, &e_update, &e_draw);
	e->start();

	return 0;
}

void e_load(void) {
	btnTest = new Button({64, 64}, {96, 16}, RAYWHITE, GRAY, BLACK);
	btnTest->onClick = btn_clicked;
	btnTest->label = "button";
}

void e_update(float delta) {
	btnTest->update(delta);
}

void e_draw() {
	btnTest->draw();
}

void btn_clicked(float delta) {
	std::cout << "clicked!" << std::endl;
	btnTest->label = "clicked!";
}
