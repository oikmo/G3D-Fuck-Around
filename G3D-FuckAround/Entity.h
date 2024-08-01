#ifndef ENTITY_H
#define ENTITY_H
#include <G3DAll.h>
#include <string>

struct Entity {
public:
	bool selected;
	std::string name;
	Entity() : selected(false) {
		name = "Entity";
	}

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
	Vector3 position;
	Vector3 size;

	BoxEntity(Vector3 position = Vector3(0,0,0), Vector3 size = Vector3(1,1,1), Color4 color = Color4(1, 1, 1, 1)) {
		this->position = position;
		this->size = size;

		this->box = Box(Vector3(this->position.x - (size.x / 2.0), this->position.y - (this->size.y / 2.0), this->position.z - (this->size.z / 2.0)),
			Vector3(position.x + (size.x / 2.0), position.y + (size.y / 2.0), position.z + (size.z / 2.0)));
		this->color = color;
		this->name = "BoxEntity";
		
		std::cout << position << " " << size << std::endl;
	}

	Color4 getColor() { return color; }
	Box getBox() { return box; }
	void printBox() {
		std::cout << position << " " << size << std::endl;
	}
};
#endif