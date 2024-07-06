#ifndef CAMERA_H
#define CAMERA_H

#include <G3DAll.h>
#include "App.h"

class Camera {
protected:
	class App* app;

	float desiredFOV;

	GCamera gcam;
	FPCameraController controller;

	Vector3 position;

public:

	virtual void init(App* app);
	virtual void move(float elapsed_time);
	virtual GCamera getG3DCamera() {
		return gcam;
	}
	virtual Vector3 getPosition() {
		return gcam.getCoordinateFrame().translation;
	}

	virtual Vector3 getRotation() {
		return gcam.getCoordinateFrame().lookVector();
	}
	virtual FPCameraController getController() {
		return controller;
	}
};

#endif
