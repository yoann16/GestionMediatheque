#pragma once
#include "Command.h"

namespace Library_Manager
{
	class ICommandFactory
	{
	public:
		virtual ~ICommandFactory() = default;
		virtual ICommand* CreateCommand(const std::vector<std::string>& params) const = 0;
		virtual information getCommandType() const = 0;
	};

	class addClientFactory : public ICommandFactory 
	{
	public:
		ICommand* CreateCommand(const std::vector<std::string>& params) const override;

		information getCommandType() const override;

	};

	class removeClientFactory : public ICommandFactory {
	public:
		ICommand* CreateCommand(const std::vector<std::string>& params) const override;
		

		information getCommandType() const override;
	};

	class listClientFactory : public ICommandFactory {
	public:
		ICommand* CreateCommand(const std::vector<std::string>& params) const override;

		information getCommandType() const override;
	};
}