#ifndef _HE_ENGINE_H
#define _HE_ENGINE_H

#include <raylib.h>

class Engine {
private:
	float delta;

	void update(float delta);
	void draw(void);

	void (*postUpdate)(float);
	void (*postDraw)(void);

public:
	Engine(void (*up)(float), void (*dr)(void));
	~Engine(void);

	void start(void);
};

#endif
