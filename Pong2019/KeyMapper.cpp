#include "KeyMapper.h"

KeyMapper* KeyMapper::m_pInstance = NULL;

KeyMapper::KeyMapper()
{
//    KeyMapper::mappingData.insert(std::pair<sf::Keyboard::Key, GameplayInputs>(sf::Keyboard::Up, GameplayInputs::P1Up));
//    KeyMapper::mappingData.insert(std::pair<sf::Keyboard::Key, GameplayInputs>(sf::Keyboard::Down, GameplayInputs::P1Down));
//    KeyMapper::mappingData.insert(std::pair<sf::Keyboard::Key, GameplayInputs>(sf::Keyboard::W, GameplayInputs::P2Up));
//    KeyMapper::mappingData.insert(std::pair<sf::Keyboard::Key, GameplayInputs>(sf::Keyboard::D, GameplayInputs::P2Down));
//    KeyMapper::mappingData.insert(std::pair<sf::Keyboard::Key, GameplayInputs>(sf::Keyboard::Escape, GameplayInputs::Menu));
//


        //mappingData.insert(std::pair<GameplayInputs, sf::Keyboard::Key>(GameplayInputs::P1Up, sf::Keyboard::Up));
        //mappingData.insert(std::pair<GameplayInputs, sf::Keyboard::Key>(GameplayInputs::P1Down, sf::Keyboard::Down));
        //mappingData.insert(std::pair<GameplayInputs, sf::Keyboard::Key>(GameplayInputs::P2Up, sf::Keyboard::W));
        //mappingData.insert(std::pair<GameplayInputs, sf::Keyboard::Key>(GameplayInputs::P2Down, sf::Keyboard::D));
        //mappingData.insert(std::pair<GameplayInputs, sf::Keyboard::Key>(GameplayInputs::Menu, sf::Keyboard::Escape));

};
KeyMapper* KeyMapper::Instance()
{
    if (!m_pInstance)
    { //NULL is 0, aka if this pointer is empty / null, then
        m_pInstance = new KeyMapper;
    }
    return m_pInstance;
}

//GameplayInputs KeyMapper::getInput()
//{
//
//    return GameplayInputs();
//}

