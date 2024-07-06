#include <G3DAll.h>
#include "App.h"
#include "Player.h"
#include "Camera.h"
#include <iostream>

void Player::init(App* app) {
	this->app = app;
	currentSpeed = 10;
	moveRate = currentSpeed;
	camera.init(app);
}

void Player::move(float elapsed_time) {
	if (app->userInput->keyDown(SDLK_LSHIFT)) {
		currentSpeed = 20.0;
		
	} else {
		if (currentSpeed != 10.0) {
			currentSpeed = 10.0;
		}
	}
	
	moveRate = lerp(moveRate, currentSpeed, elapsed_time);
	camera.getController().setMoveRate(moveRate);

	//std::cout << camera.getRotation() << std::endl;
	
	camera.move(elapsed_time);
}