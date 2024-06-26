#include "Button.hpp"

Button::Button(Vector2 pos, Vector2 s, Color c, Color h) : position(pos), size(s), color(c), hover_color(h) {}

Button::~Button() {}

void Button::update(float update) {
	Vector2 cursor_pos{(float)GetMouseX(), (float)GetMouseY()};
	hovering = false;

	if (cursor_pos.x > position.x && cursor_pos.y > position.y) {
		if (cursor_pos.x < position.x + size.x &&
			cursor_pos.y < position.y + size.y) {
			hovering = true;
		}
	}

	if (hovering && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
	}
}

void Button::draw() {
	if (hovering) {
		DrawRectangle(position.x, position.y, size.x, size.y, hover_color);
	} else {
		DrawRectangle(position.x, position.y, size.x, size.y, color);
	}
}
