#include "Engine.hpp"
#include <raylib.h>

Engine::Engine(EngineConfig c, void (*up)(float), void (*dr)(void))
	: config(c)
	, postUpdate(up)
	, postDraw(dr) {}

Engine::~Engine(void) {}

void Engine::start(void) {
	InitWindow(config.window_config.size.x, config.window_config.size.y, config.window_config.title.c_str());

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
