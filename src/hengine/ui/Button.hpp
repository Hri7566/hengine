#ifndef _HE_BUTTON_H
#define _HE_BUTTON_H

#include "raylib.h"

class Button {
public:
	Vector2 position;
	Vector2 size;
	Color color;
	Color hover_color;

	Button(Vector2 pos, Vector2 s, Color c, Color h);
	~Button();

	bool hovering;

	void update(float delta);
	void draw();
};

#endif
