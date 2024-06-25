#include "Button.hpp"

Button::Button(Vector2 pos, Vector2 s, Color c)
	: position(pos), size(s), color(c) {}

Button::~Button() {}

void Button::update(float update) {}

void Button::draw() {
	DrawRectangle(position.x, position.y, size.x, size.y, color);
}
