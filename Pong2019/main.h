#pragma once
#include <iostream>
#include <list> 
#include <iterator> 
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

bool CollisionCheck(const sf::Shape& ball, const sf::Shape& paddle) {
	return paddle.getGlobalBounds().intersects(ball.getGlobalBounds()); //this doesn't check for cornerse well.. but whatever
}

class PongBall : public sf::CircleShape {

protected:
	int radius = 10.f;
	

public:

	sf::Vector2f ballVector = sf::Vector2f(0.1, -0.2);

	PongBall( /* Pointer to the game engine*/ ) {
		setRadius(radius);
		setFillColor(sf::Color::White);
		setOrigin(radius, radius);
		setPosition(1000 / 2.0, 800 / 2.0);
	}

	void Update() {
		move(ballVector);
	}
};

class Paddles : public sf::RectangleShape{
public:
	Paddles() {
	}
};

class KeyboardInputProcessor {
public:
	KeyboardInputProcessor() {

	}
};

class DrawManager {
public:
	DrawManager() {

	}
};

