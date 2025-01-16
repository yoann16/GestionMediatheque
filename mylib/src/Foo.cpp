#include "Foo.h"
#include <iostream>

void Foo :: Display()
{
	std::cout << "Hello" << std::endl;
}
void Player::description() const
{
	std::cout << "Player" << std::endl;
}
void Enemy::description() const
{
	std::cout << "Enemy" << std::endl;
}

void PowerUp::description() const
{
	std::cout << "PowerUp" << std::endl;
}

GameObject* GameObjectFactory::create(const std::string& entity) 
{
	if (entity == "Player") 
	{
		return new Player();
	}
	else if (entity == "Enemy") 
	{
		return new Enemy();
	}
	else if (entity == "PowerUp") 
	{
		return new PowerUp();
	}
	return nullptr;
}