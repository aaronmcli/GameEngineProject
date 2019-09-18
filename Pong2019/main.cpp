
#include <iostream>
#include <list> 
#include <iterator> 
#include <chrono>
#include <ctime>
#include <SFML/Graphics.hpp>

#include "main.h"


//#include "GameObject.h"
//#include "Scene.h"

using namespace std;


// Note to self, things that we need to make:
// Menu Stack
// Input Controller, Buffering
// Sizing for window
// FPS control
// 


float windowSizeX = 1000, windowSizeY = 800;
float paddleOffset = 100;
float paddleWidth = 10.f, paddleHeight = 200.f;
float ballRadius = 10.f;

int main()
{

	//std::cout << "Hello World!\n";
	sf::RenderWindow window(sf::VideoMode(windowSizeX, windowSizeY), "SFML works!");

	//https://en.cppreference.com/w/cpp/chrono/c/clock

	sf::RectangleShape shape1(sf::Vector2f(paddleWidth, paddleHeight));
	shape1.setFillColor(sf::Color::Green);
	shape1.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
	shape1.setPosition(0 + paddleOffset, windowSizeY / 2.0);

	sf::RectangleShape shape2(sf::Vector2f(paddleWidth, paddleHeight));
	shape2.setFillColor(sf::Color::Red);
	shape2.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
	shape2.setPosition(windowSizeX - paddleOffset, windowSizeY / 2.0);

	/*sf::CircleShape ball(ballRadius);
	ball.setFillColor(sf::Color::White);
	ball.setOrigin(ballRadius, ballRadius);
	ball.setPosition(windowSizeX / 2.0, windowSizeY / 2.0);
	sf::Vector2f ballVector = sf::Vector2f(0.1, -0.2);
*/

	PongBall ball;

	sf::Font font;
	font.loadFromFile("arial.ttf");

	sf::Text p1Score("aojnbsbdfipjanbeof", font);
	p1Score.setFillColor(sf::Color::Cyan);
	p1Score.setPosition(100, 100);
	p1Score.setCharacterSize(30);

	sf::Text p2Score("aojnbsbdfipjanbeof", font);
	p2Score.setFillColor(sf::Color::Cyan);
	p2Score.setPosition(700, 100);
	p2Score.setCharacterSize(30);


	float moveSpeed = 2.0;

	bool p1Left, p1Right;
	bool p2Left, p2Right;

	while (window.isOpen())
	{

		p1Left = false, p1Right = false;
		p2Left = false, p2Right = false;

		std::time_t t = std::time(0);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			//polling for inputs
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				// move left...
				p1Left = true;

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				// move right...
				p1Right = true;
			}

			//polling for inputs
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				// move left...
				p2Left = true;

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				// move right...
				p2Right = true;
			}

		}

		//move the paddles
		if (p1Right ^ p1Left) { //xor			
			shape1.move(0, p1Right * moveSpeed + p1Left * -1 * moveSpeed);
		}
		if (p2Right ^ p2Left) { //xor			
			shape2.move(0, p2Right * moveSpeed + p2Left * -1 * moveSpeed);
		}

		//move the ball & check for scoring
		ball.Update();

		sf::Vector2f ballPos = ball.getPosition();
		
		if (ballPos.y <= ballRadius) {		
			ball.ballVector.y *= -1;
		}
		else if (ballPos.y >= (windowSizeY - ballRadius)) {
			ball.ballVector.y *= -1;
		}

		if (CollisionCheck(ball,shape1)) {
			ball.ballVector.x *= -1;
		}
		else if (CollisionCheck(ball, shape2)) {
			ball.ballVector.x *= -1;
		}

		//check for collisions

		sf::Vector2f p1Pos = shape1.getPosition();
		sf::Vector2f p2Pos = shape2.getPosition();

		shape1.setPosition(p1Pos.x, ballPos.y);
		shape2.setPosition(p2Pos.x, ballPos.y);

		//check for scoring



		
		if (ballPos.x <= ballRadius) {
			ball.setPosition(windowSizeX / 2.0, windowSizeY / 2.0);
			//p2 scored
		}
		else if (ballPos.x >= (windowSizeX - ballRadius)) {
			ball.setPosition(windowSizeX / 2.0, windowSizeY / 2.0);
			//p1 scored
		}
		

		window.clear();
		window.draw(shape1);
		window.draw(shape2);
		window.draw(ball);
		window.draw(p1Score);
		window.draw(p2Score);
		window.display();
	}

	return 0;
}

