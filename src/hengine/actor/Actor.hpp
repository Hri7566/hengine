#ifndef _HE_ACTOR_H
#define _HE_ACTOR_H

#include <string>

class Actor {
public:
	std::string id;

	virtual void update(float delta);
	virtual void draw(void);
};

#endif
