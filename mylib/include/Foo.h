#ifndef FOO_H
#define FOO_H
#include <iostream>
#include <map>
struct Foo
{
    static void display();
};
struct GameObject
{
    virtual ~GameObject() = default;
    virtual void description() = 0;
    virtual GameObject* clone() = 0;
};
struct Player : public GameObject
{
    ~Player() override;
    void description() override;
    GameObject* clone() override;
};
struct Enemy : public GameObject
{
    ~Enemy() override = default;
    void description() override;
    GameObject* clone() override;
};
struct PowerUp : public GameObject
{
    ~PowerUp() override = default;
    void description() override;
    GameObject* clone() override;
};
template<typename Key, typename Value>
class Factory
{
public:
    using Registry = std::map<Key, Value*>;
    Factory() = default;
    ~Factory()
    {
        for (auto& [key, value] : m_registry)
            delete value;

        m_registry.clear();
    }
    void registerType(const Key& key, Value* value)
    {
        if (m_registry.contains(key))
            return;

        m_registry.insert({ key, value });
    }
    Value* create(const Key& key)
    {
        if (auto it = m_registry.find(key); it == m_registry.end())
            return nullptr;
        else
            return it->second->clone();
    }
private:
    Registry m_registry;
};

class GameObjectFactory : public Factory<std::string, GameObject>
{
public:
    GameObjectFactory()
    {
        registerType("Player", new Player());
        registerType("Enemy", new Enemy);
        registerType("PowerUp", new PowerUp);
    }
};

#endif // FOO_H