#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(){
	ball.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	ball.setXVelocity(BALL_SPEED);
	ball.setYVelocity(BALL_SPEED);

	p1.setPosition(SCREEN_WIDTH / 2, 0);
	p2.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT - PADDLE_HEIGHT);
}

void Game::play(){
	window.create(sf::VideoMode(Game::SCREEN_WIDTH * 10, Game::SCREEN_HEIGHT * 10), "Pong");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(P1_LEFT)){
        	movePaddleLeft(p1);
        }
        else if (sf::Keyboard::isKeyPressed(P1_RIGHT)){
    		movePaddleRight(p1);
    	}

        if (sf::Keyboard::isKeyPressed(P2_LEFT)){
    		movePaddleLeft(p2);
    	}
    	else if (sf::Keyboard::isKeyPressed(P2_RIGHT)){
    		movePaddleRight(p2);
    	}

        window.clear();

        ball.move();
        checkBallBounce(p1, p2);
        
        drawPaddle(p1);
        drawPaddle(p2);
        drawBall();

        window.display();
    }
}

void Game::movePaddleLeft(Player &player){
	int x = player.getXPosition() - PADDLE_SPEED;
	if (x < 0){
		x = 0;
	}
	player.setPosition(x, player.getYPosition());
}

void Game::movePaddleRight(Player &player){
	int x = player.getXPosition() + PADDLE_SPEED;
	if (x + PADDLE_WIDTH > SCREEN_WIDTH){
		x = SCREEN_WIDTH - PADDLE_WIDTH;
	}
	player.setPosition(x, player.getYPosition());
}

void Game::drawPaddle(Player &player){
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(PADDLE_WIDTH * 10, PADDLE_HEIGHT * 10));
	rect.setFillColor(player.getPaintColor());
	rect.setPosition(player.getXPosition() * 10, player.getYPosition() * 10);
	window.draw(rect);
}

void Game::drawBall(){
	sf::CircleShape circle;
	circle.setRadius(BALL_RADIUS * 10);
	circle.setFillColor(ball.getPaintColor());
	circle.setPosition(ball.getXPosition() * 10, ball.getYPosition() * 10);
	window.draw(circle);
}

void Game::checkBallBounce(Player &p1, Player &p2){
	if (ball.getYPosition() < PADDLE_HEIGHT){
		// Top boundary check
		if (ball.getXPosition() > p1.getXPosition() && ball.getXPosition() + 2 * BALL_RADIUS < p1.getXPosition() + PADDLE_WIDTH){
			// Top paddle (p1) check
			ball.setYVelocity(ball.getYVelocity() * -1);

			// Set the position to the boundary, so the ball the outer if test does not pass again.
			// This was happening and causing the ball to hit the paddle and "stick" to it in the y direction.
			ball.setPosition(ball.getXPosition(), PADDLE_HEIGHT);
		}
	}
	else if (ball.getYPosition() + 2 * BALL_RADIUS > SCREEN_HEIGHT - PADDLE_HEIGHT){
		// Bottom boundary check
		if (ball.getXPosition() > p2.getXPosition() && ball.getXPosition() + 2 * BALL_RADIUS < p2.getXPosition() + PADDLE_WIDTH){
			// Bottom paddle (p2) check
			ball.setYVelocity(ball.getYVelocity() * -1);

			// Set the position to the boundary, so the ball the outer if test does not pass again.
			// This was happening and causing the ball to hit the paddle and "stick" to it in the y direction.
			ball.setPosition(ball.getXPosition(), SCREEN_HEIGHT - PADDLE_HEIGHT - 2 * BALL_RADIUS);
		}
	}
	else if (ball.getXPosition() <= 0){
		ball.setXVelocity(ball.getXVelocity() * -1);
	}
	else if (ball.getXPosition() + 2 * BALL_RADIUS >= SCREEN_WIDTH){
		ball.setXVelocity(ball.getXVelocity() * -1);
	}
}
