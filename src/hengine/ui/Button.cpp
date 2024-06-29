#include "Button.hpp"
#include <raylib.h>

Button::Button(Vector2 pos, Vector2 s, Color c, Color h, Color l) : position(pos), size(s), color(c), hover_color(h), label_color(l) {}

Button::~Button() {}

void Button::update(float delta) {
	Vector2 cursor_pos{(float)GetMouseX(), (float)GetMouseY()};
	hovering = false;

	if (cursor_pos.x > position.x && cursor_pos.y > position.y) {
		if (cursor_pos.x < position.x + size.x &&
			cursor_pos.y < position.y + size.y) {
			hovering = true;
		}
	}

	if (hovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		onClick(delta);
	}
}

void Button::draw() {
	if (hovering) {
		DrawRectangle(position.x, position.y, size.x, size.y, hover_color);
	} else {
		DrawRectangle(position.x, position.y, size.x, size.y, color);
	}

	float middle = size.x / 2;
	float text_offset = (label.length() * size.y) / 4;
	DrawText(label.c_str(), position.x + middle - text_offset, position.y, size.y, label_color);
}
