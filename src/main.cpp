#include "ui/Button.hpp"
#include <raylib.h>

int main(void) {
	InitWindow(640, 480, "hengine test program");
	SetExitKey(KEY_Q);

	float delta;

	Button btnTest({64, 64}, {96, 16}, RAYWHITE);

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
