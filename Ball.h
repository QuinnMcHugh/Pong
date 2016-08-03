#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball {
 public:
 	Ball();
 	void move();
 	
 	void setPosition(float x, float y);

 	float getXPosition();
 	float getYPosition();
 	
 	float getXVelocity();
 	float getYVelocity();

 	void setXVelocity(float x);
  	void setYVelocity(float y);

  	sf::Color getPaintColor();
  	void setPaintColor(sf::Color col);
 private:
 	float xPos, yPos;
 	float xVelo, yVelo;
 	sf::Color paintColor;
};

#endif