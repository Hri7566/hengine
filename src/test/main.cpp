#include "../hengine/ui/Button.hpp"
#include "../hengine/Engine.hpp"
#include "config.hpp"
#include <raylib.h>
#include <iostream>

void e_update(float delta);
void e_draw(void);
void btn_clicked(float delta);

int main(void) {
	EngineConfig e_config;

	e_config.window_config.size.x = WINDOW_WIDTH;
	e_config.window_config.size.y = WINDOW_HEIGHT;
	e_config.window_config.title = WINDOW_TITLE;

	Engine engine(e_config, &e_update, &e_draw);
	Button btnTest({64, 64}, {96, 16}, RAYWHITE, GRAY, BLACK);

	btnTest.onClick = btn_clicked;
	btnTest.label = "button";

	engine.start();

	return 0;
}

void e_update(float delta) {

}

void e_draw() {

}

void btn_clicked(float delta) {
	std::cout << "clicked!" << std::endl;
}
