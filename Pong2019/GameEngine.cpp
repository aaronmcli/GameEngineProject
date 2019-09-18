#include <stddef.h> //defines NULL via vcruntime.h
#include "GameEngine.h"


// Make a global static piointer used to ensure a single instance of this class
GameEngine* GameEngine::m_pInstance = NULL;

// the following function is called to create the class, or get the instance of it. 
// so there will always only be one of it

GameEngine* GameEngine::Instance() {
	if (!m_pInstance) { //NULL is 0, aka if this pointer is empty / null, then
		m_pInstance = new GameEngine;
	}
	return m_pInstance;
}