#include "../hengine/ui/Button.hpp"
#include "../hengine/Engine.hpp"
#include "config.hpp"
#include <raylib.h>
#include <iostream>

void start_window(void);
void btn_clicked(float delta);

int main(void) {
	EngineConfig e_config;

	e_config.window_config.size.x = 800;
	e_config.window_config.size.y = 600;
	e_config.window_config.title = "hengine test program";

	Engine engine(e_config);

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	SetExitKey(KEY_Q);

	float delta;
	Button btnTest({64, 64}, {96, 16}, RAYWHITE, GRAY, BLACK);

	btnTest.onClick = btn_clicked;
	btnTest.label = "button";

	while (!WindowShouldClose()) {
		delta = GetFrameTime();

		btnTest.update(delta);

		BeginDrawing();
		ClearBackground(BLACK);

		btnTest.draw();


		EndDrawing();
	}

	CloseWindow();
	return 0;
}

void btn_clicked(float delta) {
	std::cout << "clicked!" << std::endl;
}

void start_window() {

}
