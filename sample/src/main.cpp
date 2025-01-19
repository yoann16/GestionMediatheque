#include "Foo.h"
#include <iostream>
#include <vector>
#include<string>
namespace
{
	using Token = std::string;
	using TokenList = std::vector<Token>;

	TokenList splitStringBySpace(const std::string& str)
	{
		std::string workingStr = str;
		TokenList tokenList;

		while (true)
		{
			auto index = workingStr.find_first_of(' ');
			if (index == std::string::npos)
				break;

			std::string tmp(&workingStr[0], index);
			tokenList.push_back(tmp);
			workingStr = std::string(&workingStr[index + 1], workingStr.size() - (index + 1));
		}
		tokenList.push_back(workingStr);

		return tokenList;
	}

	TokenList removeEmptyTokens(const TokenList& tokens)
	{
		TokenList result;
		for (size_t i = 0; i < tokens.size(); ++i)
		{
			if (tokens[i] != "")
				result.push_back(tokens[i]);
		}
		return result;
	}

	TokenList splitIntoTokens(const std::string& str)
	{
		return removeEmptyTokens(splitStringBySpace(str));
	}
}

//Faire deux listes ancrées
struct IntNode
{
	IntNode(const int& value_)
		: value(value_)
	{
	}

	virtual ~IntNode()
	{

	}

	IntNode* prev;
	IntNode* next;
	int value;
};

struct IntrusiveList
{
	IntrusiveList()
		: m_anchor(0)
	{
		m_anchor.prev = m_anchor.next = &m_anchor;
	}

	void push_back(IntNode& node)
	{
		auto* prevNode = m_anchor.prev;

		node.prev = prevNode;
		node.next = &m_anchor;

		m_anchor.prev = &node;
		prevNode->next = &node;
	}

	bool is_empty() const
	{
		return m_anchor.prev == &m_anchor && m_anchor.next == &m_anchor;
	}

	size_t size() const
	{
		auto* currentNode = m_anchor.next;
		size_t i = 0;
		while (currentNode != &m_anchor)
		{
			++i;
			currentNode = currentNode->next;
		}

		return i;
	}

	static void remove(IntNode& node)
	{
		IntNode* prevNode = node.prev;
		IntNode* nextNode = node.next;

		prevNode->next = nextNode;
		nextNode->prev = prevNode;
		node.prev = node.next = nullptr;
	}

private:
	IntNode m_anchor;
};

struct Int : IntNode
{
	Int(const int& value_)
		: IntNode(value_)
	{
	}

	~Int()
	{
		IntrusiveList::remove(*this);
	}
};
class CompteClient
{
public:
	CompteClient(const std::string& m_name, const std::string& m_firstname, const std::string& m_age, const std::string& m_address, const std::string& m_phoneNumber, const std::string& m_mail)
		: name(m_name)
		, firstname(m_firstname)
		, age(m_age)
		, address(m_address)
		, phoneNumber(m_phoneNumber)
		, mail(m_mail)
	{
	}
	virtual ~CompteClient()
	{

	}
	CompteClient* prev;
	CompteClient* next;
	std::string name;
	std::string firstname;
	std::string age;
	std::string address;
	std::string phoneNumber;
	std::string mail;

};


class mediaType
{
public:
	mediaType()
	{
	}
	virtual ~mediaType()
	{

	}


private:
};
class Gestionnaire
{
public:
	Gestionnaire()
		:m_anchor("","","","","","")
	{
		m_anchor.prev = m_anchor.next = &m_anchor;
	}
	void addClient(CompteClient& client)
	{
		auto* prevClient = m_anchor.prev;

		client.prev = prevClient;
		client.next = &m_anchor;

		m_anchor.prev = &client;
		prevClient->next = &client;

	}
	static void removeClient(CompteClient& client)
	{
		CompteClient* prevClient = client.prev;
		CompteClient* nextClient = client.next;

		prevClient->next = nextClient;
		nextClient->prev = prevClient;
		client.prev = client.next = nullptr;
	}
	size_t listClient() const
	{
		auto* currentClient = m_anchor.next;
		size_t i = 0;
		while (currentClient != &m_anchor)
		{
			std::cout << currentClient->name << std::endl;
			std::cout << currentClient->firstname << std::endl;
			std::cout << currentClient->age << std::endl;
			std::cout << currentClient->address << std::endl;
			std::cout << currentClient->phoneNumber << std::endl;
			std::cout << currentClient->mail << std::endl;
			++i;
			currentClient = currentClient->next;
			
		}
		
		return i;
	}
	bool isEmpty() const
	{
		return m_anchor.prev == &m_anchor && m_anchor.next == &m_anchor;
	}
private:
	CompteClient m_anchor;
};

class Client : public CompteClient
{
public:
	Client(const std::string& m_name, const std::string& m_firstname, const std::string& m_age, const std::string& m_address, const std::string& m_phoneNumber, const std::string& m_mail)
		: CompteClient(m_name, m_firstname, m_age, m_address, m_phoneNumber, m_mail)
		
	{

	}
	~Client()
	{
		Gestionnaire::removeClient(*this);
	}
};






int main()
{
	
	
	Gestionnaire Gest;
	std::cout << Gest.listClient() << std::endl;
	Client A("Yoann","Joseph","24","20quaiArmandLalande","0648750814","yoannjoseph16062000@gmail.com");
	Gest.addClient(A);
	std::cout << Gest.listClient() << std::endl;
	{
		Client B("Quentin", "Joseph", "28", "10routedesfossés...", "06247840", "quentinjoseph@gmail.com");
		Gest.addClient(B);
		std::cout << Gest.listClient() << std::endl;
	}

	std::cout << Gest.listClient() << std::endl;
	return 0;

	/*GameObject* entity = nullptr;
	{
		GameObjectFactory factory;
		entity = factory.create("Player");
	}
	entity->description();
	delete entity;
	return 0;*/


	/*InTrusiveList list;
	Int t(3);
	Int a(4);
	list.pushBack(t);
	list.pushBack(a);
	std::cout << list.size() << std::endl;

	{
		Int tmp(6);
		list.pushBack(tmp);
		std::cout << list.size() << std::endl;
	}

	std::cout << list.size() << std::endl;

	return 0;*/
}
