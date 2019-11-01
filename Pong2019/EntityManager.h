#include <list> 
#include <vector>
#include <iterator> 

#pragma once
class Entity
{
	int entityID;
};

class EntityManager
{
};


// Systems are classes that makes up for the components in each of the
// entity, they may register with these systems so they can do stuff in that 
// system.
 class Component
{
	// every systems has a list of entity that it needs to service, and it is
	// registered with the system.

	// LIST OF ENTITY HERE
	std::vector<Entity> entityStack;

	Component() {
	
	};
	
	void RegisterEntity(Entity e){
		//add entity to  list of things it needs to support
		entityStack.insert(entityStack.begin(),e);
		return;
	}

	virtual void Update() {
		//we need a way to update things 
	}
};