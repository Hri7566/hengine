#include "Engine.hpp"

Engine::Engine(void (*up)(float), void (*dr)(void)) : postUpdate(up), postDraw(dr) {}

Engine::~Engine(void) {}

void Engine::start(void) {
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
