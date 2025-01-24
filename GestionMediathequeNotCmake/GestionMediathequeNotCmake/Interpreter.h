#pragma once
#include "Exception.h"
#include "CommandManager.h"

namespace Library_Manager
{
	class Interpreter
	{
	public:
		Interpreter(CommandManager& commandManager);

		void init();
		void Input(const std::string& input);
		CommandManager& getCommandManager();
		
	private:
		bool m_isInitialized;
		CommandManager& m_commandManager;
	};
}