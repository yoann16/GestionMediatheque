#include "CommandManager.h"
namespace Library_Manager
{
    CommandManager::~CommandManager()
    {
        for (auto& pair : m_factories)
        {
            delete pair.second;
        }
    }

    void CommandManager::addFactory(ICommandFactory* factory)
    {
        m_factories[factory->getCommandType()] = factory;
    }

    void CommandManager::create_Command(const information& commandType, const Command& params)
    {
        auto it = m_factories.find(commandType);
        if (it == m_factories.end())
        {
            throw UnknownCommandException();
        }

        ICommand* command = it->second->CreateCommand(params);
        command->apply();
        m_history.push_back(commandType);
        delete command;
    }
    void CommandManager::printHistory() const
    {
        std::cout << "History of created command:\n";
        for (const auto& commandType : m_history)
        {
            std::cout << "- " << commandType << "\n";
        }
    }

    CommandManager& getGlobalCommandManager()
    {
        static CommandManager manager;
        return manager;
    }

    void registerCommands()
    {
        getGlobalCommandManager().addFactory(new addClientFactory());
        getGlobalCommandManager().addFactory(new removeClientFactory());
        getGlobalCommandManager().addFactory(new listClientFactory());
    }

}