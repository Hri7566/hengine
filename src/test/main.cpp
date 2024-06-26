#include "../hengine/ui/Button.hpp"
#include "config.hpp"
#include <raylib.h>

void start_window(void);

int main(void) {
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	SetExitKey(KEY_Q);

	float delta;

	Button btnTest({64, 64}, {96, 16}, RAYWHITE, GRAY);

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

void start_window() {

}
