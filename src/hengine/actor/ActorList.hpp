#ifndef _HE_ACTOR_LIST_H
#define _HE_ACTOR_LIST_H

#include <vector>
#include <string>
#include "Actor.hpp"

class ActorList {
private:
	std::vector<Actor> list;

public:
	void add(Actor a);
	void remove(std::string id);
};

#endif
