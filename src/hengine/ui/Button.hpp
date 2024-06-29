#ifndef _HE_BUTTON_H
#define _HE_BUTTON_H

#include "../actor/Actor.hpp"
#include <raylib.h>
#include <string>

class Button : Actor {
public:
	Vector2 position;
	Vector2 size;

	Color color;
	Color hover_color;

	std::string label;
	Color label_color;

	void (*onClick)(float delta);

	Button(Vector2 pos, Vector2 s, Color c, Color h, Color l);
	~Button();

	bool hovering;

	void update(float delta);
	void draw();
};

#endif
