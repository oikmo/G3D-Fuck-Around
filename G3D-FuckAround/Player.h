#ifndef PLAYER_H
#define PLAYER_H
#include <G3DAll.h>
#include "App.h"
#include "Camera.h"

class Player {
protected:
	class App* app;

	class Camera camera;
	float currentSpeed;
	float moveRate;
	class CoordinateFrame cFrame;
	virtual void handleMovement(float elapsed_time);
public:
	virtual void init(App* app);
	virtual void move(float elapsed_time);

	

	virtual Camera getCamera() { return camera; }
};

#endif