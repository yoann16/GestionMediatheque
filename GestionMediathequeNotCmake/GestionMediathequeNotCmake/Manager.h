#pragma once
#include <vector>
#include "ClientAccount.h"
class ClientManager 
{
public:
    static void addClient(
        const std::string& name, const std::string& firstname,
        int age, const std::string& address,
        const std::string& phoneNumber, const std::string& mail);

    static void removeClient(const std::string& identifier);
    static void listClients();
private:
    static std::vector<ClientAccount> m_clients;
};