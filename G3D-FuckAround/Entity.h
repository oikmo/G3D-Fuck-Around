#ifndef ENTITY_H
#define ENTITY_H
#include <G3DAll.h>

struct Entity {
public:
	bool selected;
	Entity() : selected(false) {}

	virtual void render(RenderDevice* renderDevice);
	//** Returns amount of time to intersection starting at ray.origin and traveling with ray.velocity. */
	virtual RealTime getIntersectionTime(const Ray& ray);
	virtual void destroy() {
		//entityList.remove(entityList.findIndex(this));
	}
};

class BoxEntity : public Entity {
protected:
	Box box;
	Color4 color;
public:
	BoxEntity(Vector3 position, Vector3 size, Color4 color = Color4(1, 1, 1, 1)) {
		this->box = Box(Vector3(position.x - (size.x / 2.0), position.y - (size.y / 2.0), position.z - (size.z / 2.0)),
			Vector3(position.x + (size.x / 2.0), position.y + (size.y / 2.0), position.z + (size.z / 2.0)));
		this->color = color;
	}

	Color4 getColor() { return color; }
	Box getBox() { return box; }
};
#endif