#include "Engine.hpp"
#include <raylib.h>

Engine::Engine(EngineConfig c, void (*up)(float), void (*dr)(void))
	: config(c)
	, postUpdate(up)
	, postDraw(dr) {}

Engine::~Engine(void) {}

void Engine::start(void) {
	InitWindow(640, 480, "hengine");

	while (!WindowShouldClose()) {
		delta = GetFrameTime();
		update(delta);

		BeginDrawing();

		draw();

		EndDrawing();
	}
}

void Engine::update(float delta) {
	postUpdate(delta);
}

void Engine::draw(void) {
	postDraw();
}
