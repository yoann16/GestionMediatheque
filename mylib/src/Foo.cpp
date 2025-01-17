#include "Foo.h"
#include <iostream>

void Foo::display()
{
	std::cout<<"Hello" << std::endl;
}
Player:: ~Player()
{
    std::cout << "Game Over" << std::endl;
}
void Player::description()
{
    std::cout << "Player" << std::endl;
}
GameObject* Player::clone()
{
    return new Player();
}
void Enemy::description()
{
    std::cout << "Enemy" << std::endl;
}
GameObject* Enemy::clone()
{
    return new Enemy();
}
void PowerUp::description()
{
    std::cout << "PowerUp" << std::endl;
}
GameObject* PowerUp::clone()
{
    return new PowerUp();
}