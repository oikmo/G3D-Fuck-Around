#include <G3DAll.h>
#include "Entity.h"

void Entity::render(RenderDevice* renderDevice) {
	BoxEntity* ent = (BoxEntity*)this;
	Draw::box(ent->getBox(), renderDevice, ent->getColor(), Color4(0, 0, 0, 0));
}

RealTime Entity::getIntersectionTime(const Ray& ray) {
	return 0;
}