#ifndef _HE_ENGINE_H
#define _HE_ENGINE_H

#include <raylib.h>
#include <string>
#include "actor/ActorList.hpp"

typedef struct WindowConfig {
	Vector2 size;
	std::string title;
} WindowConfig;

typedef struct EngineConfig {
	WindowConfig window_config;
} EngineConfig;

class Engine {
private:
	float delta;

	void load(void);
	void update(float delta);
	void draw(void);

	void (*postLoad)();
	void (*postUpdate)(float);
	void (*postDraw)(void);

public:
	ActorList actor_list;
	EngineConfig config;

	Engine(EngineConfig c, void (*l)(void), void (*up)(float), void (*dr)(void));
	~Engine(void);

	void start(void);
	float get_delta(void);
};

#endif
