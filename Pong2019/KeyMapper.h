#pragma once
#include "InputProcessor.h"

//associative array

enum GameplayInputs
{
    P1Up,
    P1Down,
    P2Up,
    P2Down,
    Menu
};

class KeyMapper
{
public:

    static KeyMapper* Instance();
    static std::map<GameplayInputs, sf::Keyboard::Key> mappingData;
    //static GameplayInputs getInput();
    void Init();



private:
    
    KeyMapper();
    //{ //private so you can't make more.
        //mappingData.insert(std::pair<GameplayInputs, sf::Keyboard::Key>(GameplayInputs::P1Up, sf::Keyboard::Up));
        //mappingData.insert(std::pair<GameplayInputs, sf::Keyboard::Key>(GameplayInputs::P1Down, sf::Keyboard::Down));
        //mappingData.insert(std::pair<GameplayInputs, sf::Keyboard::Key>(GameplayInputs::P2Up, sf::Keyboard::W));
        //mappingData.insert(std::pair<GameplayInputs, sf::Keyboard::Key>(GameplayInputs::P2Down, sf::Keyboard::D));
        //mappingData.insert(std::pair<GameplayInputs, sf::Keyboard::Key>(GameplayInputs::Menu, sf::Keyboard::Escape));
    //}; 

    KeyMapper(KeyMapper const&) {}; //This is a copy constructor, we made it private so you can't make more of it either (when passing into another method).
    KeyMapper& operator=(KeyMapper const&) {}; //assignment operator is private
    static KeyMapper* m_pInstance;

};

