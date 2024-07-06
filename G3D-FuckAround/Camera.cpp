#include <G3DAll.h>
#include "App.h"
#include "Camera.h"

UserInput* userInput;

void Camera::init(App* app) {
	this->app = app;
	userInput = app->userInput;

	controller.init(app->renderDevice, app->userInput);
	controller.setMoveRate(10);
	controller.setPosition(Vector3(0, 0, 4));
	controller.lookAt(Vector3(0, 0, 0));
	controller.setActive(true);
}

void Camera::move(float elapsed_time) {
	if (userInput->keyDown(SDLK_LSHIFT)) {
		this->desiredFOV = 80.0;
	} else {
		if (this->desiredFOV != 60.0) {
			this->desiredFOV = 60.0;
		}
	}

	controller.doSimulation(elapsed_time);
	gcam.setCoordinateFrame(controller.getCoordinateFrame());
	gcam.setFieldOfView(lerp(gcam.getFieldOfView(), toRadians(this->desiredFOV), (double)elapsed_time));
}
