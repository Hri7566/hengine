#ifndef _TEST_BOX_H
#define _TEST_BOX_H

#include "../hengine/actor/Actor.hpp"
#include <raylib.h>

class Box : public Actor {
public:
	Vector2 position;
	Vector2 size;

	Color color;

	Box(Vector2 p, Vector2 s, Color c);

	void update(float delta);
	void draw();
};

#endif
