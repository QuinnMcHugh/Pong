#include "Player.h"

Player::Player(){
	xPos = yPos = 0;
	paintColor = sf::Color::Blue;
}

void Player::setPosition(int x, int y){
	xPos = x;
	yPos = y;
}

int Player::getXPosition(){
	return xPos;
}

int Player::getYPosition(){
	return yPos;
}

sf::Color Player::getPaintColor(){
	return paintColor;
}

void Player::setPaintColor(sf::Color col){
	paintColor = col;
}
