#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
 public:
 	Player();
 
 	void setPosition(int x, int y);

 	int getXPosition();
 	int getYPosition();

 	sf::Color getPaintColor();
 	void setPaintColor(sf::Color col);
 private:
 	int xPos, yPos;
 	sf::Color paintColor;
};

#endif