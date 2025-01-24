#pragma once
#include <map>

#include "CommandFactory.h"
#include "Exception.h"

namespace Library_Manager
{
	class CommandManager
	{
	private:
		std::map<information, ICommandFactory*> m_factories;
		std::vector<information>m_history;
	public:
		~CommandManager();

		void addFactory(ICommandFactory* factory);
		void create_Command(const information& commandType, const Command& params);
		void printHistory() const;
	};
	CommandManager& getGlobalCommandManager();
	void registerCommands();
}