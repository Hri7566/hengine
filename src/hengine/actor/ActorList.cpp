#include "ActorList.hpp"
#include <cstring>

void ActorList::add(Actor *a) {
	list.push_back(a);
}

void ActorList::remove(std::string id) {
	int i = 0;

	for (Actor *a : list) {
		if (strcmp(a->id.c_str(), id.c_str()) == 0) {
			list.erase(list.begin() + i);
			break;
		}

		i++;
	}
}

void ActorList::update(float delta) {
	for (Actor *a : list) {
		a->update(delta);
	}
}

void ActorList::draw(void) {
	for (Actor *a : list) {
		a->draw();
	}
}
