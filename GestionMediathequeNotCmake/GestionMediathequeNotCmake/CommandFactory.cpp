#include "CommandFactory.h"

namespace Library_Manager
{
	ICommand* addClientFactory::CreateCommand(const std::vector<std::string>& params) const
	{
		if (params.size() != 7)
		{
			throw std::runtime_error("Invalid parameters for addClient");
		}
		return new addClientCommand
		(
			params[1], params[2], std::stoi(params[3]),
			params[4], params[5], params[6]
		);
	}

	information addClientFactory::getCommandType() const
	{
		return "addClient";
	}

	ICommand* removeClientFactory:: CreateCommand(const std::vector<std::string>& params) const 
	{
		if (params.size() < 2 || params.size() > 3)
		{
			throw std::runtime_error("Invalid parameters for removeClient");
		}
		return new removeClientCommand(params[1]);
	}

	information removeClientFactory:: getCommandType() const 
	{
		return "removeClient";
	}

	ICommand* listClientFactory:: CreateCommand(const std::vector<std::string>& params) const 
	{
		if (params.size() != 1)
		{
			throw std::runtime_error("listClient takes no parameters");
		}
		return new listClientCommand();
	}

	information listClientFactory:: getCommandType() const 
	{
		return "listClient";
	}
}