#include "InputProcessor.h"
#include "KeyMapper.h"

//CPP contains the Constructors and the member functions.. Data definations should go into the header file


// Make a global static piointer used to ensure a single instance of this class
InputProcessor* InputProcessor::m_pInstance = NULL;

// the following function is called to create the class, or get the instance of it. 
// so there will always only be one of it

InputProcessor* InputProcessor::Instance()
{
    if (!m_pInstance)
    { //NULL is 0, aka if this pointer is empty / null, then
        m_pInstance = new InputProcessor;
    }
    return m_pInstance;
}

void InputProcessor::Update(sf::RenderWindow* window)
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window->close();
        }
        //polling for inputs
        //run through all the keymappings
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            // move left...
            //p1Left = true;
        }
    }
    return;
}

//bool InputProcessor::isKeyPressed(GameplayInputs key)
//{
//
//    return false;
//}
