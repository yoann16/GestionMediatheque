#include "Api.h"
#include "Command.h"
namespace Library_Manager
{
	Interpreter& API::getInterpreter()
	{
		static CommandManager commandManager;
		static Interpreter interpreter(commandManager);
		return interpreter;
	}

	void API::cmd_init()
	{
		registerCommands();
		getInterpreter().init();
	}
	void API::cmd_input()
	{
		std::string input;
		while (true) 
		{
			std::cout << "> ";
			if (!std::getline(std::cin, input)) 
			{
				std::cerr << "Error reading input.\n";///////
				break;
			}

			if (input == "exit") 
			{ // Commande pour quitter
				std::cout << "Exiting...\n";
				break;
			}

			try 
			{
				getInterpreter().Input(input);
			}
			catch (const std::exception& e) 
			{
				std::cout << "Exception: " << e.what() << "\n";
			}
		}
	}
}