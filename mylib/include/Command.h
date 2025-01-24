#pragma once

#include <iostream>// TODO a enlever

#include "BaseType.h"
#include "Manager.h"

namespace Library_Manager
{
	class ICommand
	{
	public:
		virtual ~ICommand() = default;
		virtual void apply() const = 0;
	};

	class addClientCommand : public ICommand 
	{
	private:
		std::string m_name, m_firstname, m_address, m_phoneNumber, m_mail;
		int m_age;

	public:
		addClientCommand(const std::string& name, const std::string& firstname, int age,
			const std::string& address, const std::string& phoneNumber,
			const std::string& mail);

		void apply() const override;
	};

	class removeClientCommand : public ICommand 
	{
	private:
		std::string m_identifier;

	public:
		removeClientCommand(const std::string& identifier);

		void apply() const override;
	};

	class listClientCommand : public ICommand 
	{
	public:
		void apply() const override;
	};
}