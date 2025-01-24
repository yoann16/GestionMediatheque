#include "Command.h"
namespace Library_Manager
{
	addClientCommand::addClientCommand(const std::string& name, const std::string& firstname, int age,
		const std::string& address, const std::string& phoneNumber,
		const std::string& mail)
		: m_name(name), m_firstname(firstname), m_age(age),
		m_address(address), m_phoneNumber(phoneNumber), m_mail(mail)
	{
	}
	void addClientCommand:: apply() const
	{
		ClientManager::addClient(m_name, m_firstname, m_age, m_address, m_phoneNumber, m_mail);
	}
	removeClientCommand::removeClientCommand(const std::string& identifier)
		: m_identifier(identifier)
	{
	}
	void removeClientCommand:: apply() const
	{
		ClientManager::removeClient(m_identifier);
	}
	void listClientCommand::apply() const 
	{
		ClientManager::listClients();
	}
}