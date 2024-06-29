#include "box.hpp"
#include <raylib.h>

Box::Box(Vector2 p, Vector2 s, Color c) : position(p), size(s), color(c) {}

void Box::update(float delta) {}

void Box::draw(void) {
	DrawRectangle(position.x, position.y, size.x, size.y, color);
}
