#pragma once
#include <string>

struct Foo
{
	static void Display();
};
struct GameObject
{
	virtual ~GameObject() = default;
	virtual void description() const = 0;

};

struct Player : public GameObject
{
	~Player() override = default;
	void description() const override;

};

struct Enemy : public GameObject
{
	~Enemy() override = default;
	void description() const override;
};

struct PowerUp : public GameObject
{
	~PowerUp() override = default;
	void description() const override;
};
class GameObjectFactory
{
public:
	GameObject* create(const std::string& entity);

	//void registerType();//utilisation d'une map {key,value}
private:

};
