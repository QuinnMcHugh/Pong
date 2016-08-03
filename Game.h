#ifndef GAME_H
#define GAME_H

#include "Ball.h"
#include "Player.h"

#include <SFML/Graphics.hpp>

class Game {
 public:
 	Game();

 	void play();
 	void drawP1Paddle();
 	void drawP2Paddle();
 	void drawBall();
 	bool isOver();
 	void movePaddleLeft(Player &player);
 	void movePaddleRight(Player &player);
 	void drawPaddle(Player &player);
 	void checkBallBounce(Player &p1, Player &p2);


 	static const float PADDLE_SPEED = 1;
 	static const float BALL_SPEED = .3;
 	
 	static const int SCREEN_WIDTH = 64;
 	static const int SCREEN_HEIGHT = 96;

 	static const sf::Keyboard::Key P1_LEFT = sf::Keyboard::Left;
 	static const sf::Keyboard::Key P1_RIGHT = sf::Keyboard::Right;
 	static const sf::Keyboard::Key P2_LEFT = sf::Keyboard::A;
 	static const sf::Keyboard::Key P2_RIGHT = sf::Keyboard::D;

 	static const int PADDLE_HEIGHT = 2;
 	static const int PADDLE_WIDTH = 8;

 	static const int BALL_RADIUS = 1;
 private:
 	Player p1, p2;
 	Ball ball;
 	sf::RenderWindow window;
};

#endif