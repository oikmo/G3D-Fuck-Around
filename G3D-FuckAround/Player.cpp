#include <G3DAll.h>
#include "App.h"
#include "Player.h"
#include "Camera.h"
#include <iostream>

Vector3 position;

void Player::init(App* app) {
	this->app = app;
	currentSpeed = 10;
	moveRate = currentSpeed;
	camera.init(app);
	position = camera.getPosition();
}

void Player::move(float elapsed_time) {
	if (app->userInput->keyDown(SDLK_LSHIFT)) {
		currentSpeed = 15.0;
		
	} else {
		if (currentSpeed != 5.0) {
			currentSpeed = 5.0;
		}
	}
	
	moveRate = lerp(moveRate, currentSpeed*5, elapsed_time);
	
	//std::cout << (moveRate * elapsed_time) << std::endl;
	handleMovement(elapsed_time);
	camera.move(position, elapsed_time);
	
}

void Player::handleMovement(float elapsed_time) {
	if (app->userInput->keyDown(SDLK_w)) {
		position += camera.getFrame().lookVector() * (moveRate * elapsed_time);
	}
	if (app->userInput->keyDown(SDLK_s)) {
		position -= camera.getFrame().lookVector() * (moveRate * elapsed_time);
	}
	if (app->userInput->keyDown(SDLK_d)) {
		position += camera.getFrame().rightVector() * (moveRate * elapsed_time);
	}
	if (app->userInput->keyDown(SDLK_a)) {
		position -= camera.getFrame().rightVector() * (moveRate * elapsed_time);
	}
}