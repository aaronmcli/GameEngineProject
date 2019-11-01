#pragma once
#include <SFML/Graphics.hpp>

class GameEngine {

public:
	static GameEngine* Instance(); 
	//statics methods can not be overriden by their child.
	//static class methods can be called without creating an instance of that class.
	//A static member is shared by all objects of the class. 
	//All static data is initialized to zero when the first object is created, if no other initialization is present. 

	//Control Input Mapper - A key is mapped to what action.

	//List of All Game Objects in the game

	//state of the game
	bool gamePaused = false;

	//screen stack

	//

private:
	GameEngine() {}; //private so you can't make more.
	GameEngine(GameEngine const&) {}; //This is a copy constructor, we made it private so you can't make more of it either (when passing into another method).
	GameEngine& operator=(GameEngine const&) {}; //assignment operator is private
	static GameEngine* m_pInstance;
}; 


//REFERENCES VS POINTERS
// References can not be null, pointers can be
// References msut be initalized to an object, and can not be changed to another object.
// References must be initalized when created, pointers can be done anytime.

// what is the difference between references and a variable name?
// is a varaible name effectively the first reference to a variable?

//int i = 17 ; <-- declaring a variable
//int& r = i; <-- declaring a reference to variable i.

class SceneManager {

public:
	static SceneManager* Instance();
	//Scene s;

private:
	SceneManager() {}; //private so you can't make more.
	SceneManager(SceneManager const&) {}; //This is a copy constructor, we made it private so you can't make more of it either (when passing into another method).
	SceneManager& operator=(SceneManager const&) {}; //assignment operator is private
	static SceneManager* m_pInstance;
};

class Scene {


};

class GameObject {	virtual void Update() {	} };
class Movement : virtual public GameObject { void Update(); };
class Score : virtual public GameObject { void Update(int delta); };
class Shape : virtual public GameObject { void Update(); };

class PongBall : public sf::CircleShape  {
protected:
	float radius = 10.f;


public:

	sf::Vector2f ballVector = sf::Vector2f(0.1f, -0.2f);

	PongBall( /* Pointer to the game engine*/) {
		setRadius(radius);
		setFillColor(sf::Color::White);
		setOrigin(radius, radius);
		setPosition(1000 / 2.0, 800 / 2.0);
	}

	void Update() {
		move(ballVector);
	}
};
