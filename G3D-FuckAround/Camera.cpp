#include <G3DAll.h>
#include "App.h"
#include "Camera.h"

UserInput* userInput;

void Camera::init(App* app) {
	this->app = app;
	userInput = app->userInput;

	controller.init(app->renderDevice, app->userInput);
	controller.setMoveRate(10);
	controller.setPosition(Vector3(0, 4, 0));
	controller.lookAt(Vector3(0, 4, 0));
	controller.setActive(true);
}

void Camera::move(Vector3 position, float elapsed_time) {
	//userInput->setMouseXY(Vector2(0, 0));
	if (userInput->keyDown(SDLK_LSHIFT)) {
		this->desiredFOV = 80.0;
	} else {
		if (this->desiredFOV != 60.0) {
			this->desiredFOV = 60.0;
		}
	}
	gcam.setFieldOfView(lerp(gcam.getFieldOfView(), toRadians(this->desiredFOV), (double)elapsed_time));
	
	pan(position, userInput->mouseDXY().x, userInput->mouseDXY().y);
	//std::cout << userInput->mouseDXY().x << " " << userInput->mouseDXY().y << std::endl;
	gcam.setCoordinateFrame(frame);
	
}

void Camera::pan(Vector3 position, float spdX, float spdY) {
	Vector3 pos;

	yaw += spdX / 50.0;
	pitch += spdY / 50.0;

	if (pitch > 1.4f) pitch = 1.4f;
	if (pitch < -1.4f) pitch = -1.4f;

	frame.translation = Vector3(sin(-yaw) * cos(pitch), sin(pitch), cos(-yaw) * cos(pitch)) + position;
	frame.lookAt(position);
}