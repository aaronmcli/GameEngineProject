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

