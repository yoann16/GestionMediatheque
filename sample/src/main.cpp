#include "Foo.h"
#include <iostream>

int main()
{
	GameObject* entity = nullptr;
	{
		GameObjectFactory factory;
		entity = factory.create("Player");
	}
	entity->description();
	delete entity;
	return 0;
}
