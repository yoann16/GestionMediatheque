#pragma once
#include <iostream>
#include <string>

class ClientAccount;
class InfoClient
{
	friend class ClientAccount;
public:
	InfoClient(const std:: string& Name, const std::string& FirstName, int Age, const std::string& Address,const std::string& PhoneNumber,const std::string& Mail)
		:m_Name(Name)
		, m_FirstName(FirstName)
		, m_Age(Age)
		, m_Address(Address)
		, m_PhoneNumber(PhoneNumber)
		, m_Mail(Mail)
	{ }
	std::string getName() const { return m_Name; }
	std::string getFirstName() const { return m_FirstName; }
	std::string getMail() const { return m_Mail; }

	

private:
	std::string m_Name;
	std::string m_FirstName;
	int m_Age;
	std::string m_Address;
	std::string m_PhoneNumber;
	std::string m_Mail;
};

class ClientAccount
{
public:
	ClientAccount(InfoClient& info)
	{
		m_info = new InfoClient(info);
	}
	~ClientAccount()
	{
		delete m_info;
		m_info = nullptr;

	}
	InfoClient* getInfo() const { return m_info; }


	void ShowInfoClient() const
	{
		std::cout << "Client : " << m_info->m_Name << " " << m_info->m_FirstName << std::endl;
		std::cout << "Age : " << m_info->m_Age << std::endl;
		std::cout << "Address : " << m_info->m_Address << std::endl;
		std::cout << "Phone : " << m_info->m_PhoneNumber << std::endl;
		std::cout << "Mail : " << m_info->m_Mail << std::endl;
	}
private:
	InfoClient* m_info;
};