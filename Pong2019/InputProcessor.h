#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>


class InputProcessor
{
public:
	static InputProcessor* Instance();
    //public sf::RenderWindow* window;
    
private:
	InputProcessor() {}; //private so you can't make more.
	InputProcessor(InputProcessor const&) {}; //This is a copy constructor, we made it private so you can't make more of it either (when passing into another method).
	InputProcessor& operator=(InputProcessor const&) {}; //assignment operator is private
	static InputProcessor* m_pInstance;

    void Update();

};

