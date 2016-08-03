#include "Ball.h"

Ball::Ball(){
	xPos = yPos = 0;
	xVelo = yVelo = 1;
	paintColor = sf::Color::White;
}

void Ball::move(){
	xPos += xVelo;
	yPos += yVelo;
}

void Ball::setPosition(float x, float y){
	xPos = x;
	yPos = y;
}

float Ball::getXPosition(){
	return xPos;
}

float Ball::getYPosition(){
	return yPos;
}

float Ball::getXVelocity(){
	return xVelo;
}

float Ball::getYVelocity(){
	return yVelo;
}

void Ball::setXVelocity(float x){
	xVelo = x;
}

void Ball::setYVelocity(float y){
	yVelo = y;
}

sf::Color Ball::getPaintColor(){
	return paintColor;
}

void Ball::setPaintColor(sf::Color col){
	paintColor = col;
}