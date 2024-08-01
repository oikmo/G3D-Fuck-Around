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

	CoordinateFrame frame;
	Vector3 startFocus;
	Vector3 focusPosition;

	float yaw, pitch;

public:

	virtual void init(App* app);
	virtual void move(Vector3 position, float elapsed_time);
	virtual GCamera getG3DCamera() {
		return gcam;
	}	
	virtual Vector3 getPosition() {
		return gcam.getCoordinateFrame().translation;
	}

	virtual Vector3 getRotation() {
		return frame.lookVector();
	}
	virtual FPCameraController getController() {
		return controller;
	}

	CoordinateFrame getFrame() {
		return frame;
	}


	virtual void pan(Vector3 position, float spdX, float spdY);

};

#endif
