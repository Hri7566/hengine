#include "Engine.hpp"
#include <raylib.h>

bool *should_update;
bool *should_draw;

Engine::Engine(EngineConfig c, void (*l)(void), void (*up)(float), void (*dr)(void))
	: config(c)
	, postLoad(l)
	, postUpdate(up)
	, postDraw(dr)
{
	should_update = (bool *)malloc(sizeof(bool));
	should_draw = (bool *)malloc(sizeof(bool));

	*should_update = postUpdate != nullptr;
	*should_draw = postDraw != nullptr;
}

Engine::~Engine(void) {
	free(should_update);
	free(should_draw);
}

void Engine::start(void) {
	InitWindow(config.window_config.size.x, config.window_config.size.y, config.window_config.title.c_str());

	this->load();

	while (!WindowShouldClose()) {
		delta = GetFrameTime();
		update(delta);

		BeginDrawing();
		draw();
		EndDrawing();
	}

	CloseWindow();
}

void Engine::load() {
	//SetExitKey(KEY_NULL);
	postLoad();
}

void Engine::update(float delta) {
	actor_list.update(delta);
	if (should_update) postUpdate(delta);
}

void Engine::draw(void) {
	actor_list.draw();
	if (should_draw) postDraw();
}
