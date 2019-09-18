#pragma once

class GameEngine {

public:
	static GameEngine* Instance(); 
	//statics methods can not be overriden by their child.
	//static class methods can be called without creating an instance of that class.
	//A static member is shared by all objects of the class. 
	//All static data is initialized to zero when the first object is created, if no other initialization is present. 

private:
	GameEngine() {}; //private so you can't make more.
	GameEngine(GameEngine const&) {}; //This is a copy constructor, we made it private so you can't make more of it either.
	GameEngine& operator=(GameEngine const&) {}; //assignment operator is private
	static GameEngine* m_pInstance;
};