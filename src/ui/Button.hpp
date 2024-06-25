#ifndef _HE_BUTTON_H
#define _HE_BUTTON_H

#include "raylib.h"

class Button {
public:
	Vector2 position;
	Vector2 size;
	Color color;

	Button(Vector2 pos, Vector2 s, Color c);
	~Button();

	void update(float delta);
	void draw();
};

#endif
