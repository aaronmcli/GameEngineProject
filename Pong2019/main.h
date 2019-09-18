#include <iostream>
#include <list> 
#include <iterator> 
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

bool CollisionCheck(sf::CircleShape ball, sf::RectangleShape paddle) {
	sf::Vector2f ballPosition = ball.getPosition();
	float ballRadius = ball.getRadius();


	sf::Vector2f playerPosition = paddle.getPosition();

	return false;
}