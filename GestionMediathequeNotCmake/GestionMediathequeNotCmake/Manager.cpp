#include "Manager.h"
#include "ClientAccount.h"

std::vector<ClientAccount> ClientManager::m_clients;

 

void ClientManager::addClient(

    const std::string& name, const std::string& firstname,
    int age, const std::string& address,
    const std::string& phoneNumber, const std::string& mail)
{
    InfoClient info(name, firstname, age, address, phoneNumber, mail);
    m_clients.emplace_back(info);
    std::cout << "Client added: " << name << " " << firstname << std::endl;
}

void ClientManager::removeClient(const std::string& identifier) 
{
    auto it = std::remove_if(m_clients.begin(), m_clients.end(),
        [&identifier](const ClientAccount& client) 
        {
            
            if (client.getInfo()->getName() == identifier) return true;

            // Comparer avec le prénom
            if (client.getInfo()->getFirstName() == identifier) return true;

            // Comparer avec le mail
            if (client.getInfo()->getMail() == identifier) return true;

            return false;
        });

    m_clients.erase(it, m_clients.end());
}

void ClientManager::listClients() 
{
    for (const auto& client : m_clients) 
    {
        client.ShowInfoClient();
        std::cout << "-------------------\n";
    }
}