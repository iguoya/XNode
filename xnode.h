#ifndef XNODE_H
#define XNODE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>


#include "client.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;


using namespace std;

class XNode
{
public:
    XNode();
    ~XNode();

    void listen(uint16_t port);

    void operator()(string name, uint16_t port);


    void contact(string ip, uint16_t port);


//    vector<Client> clients;
private:

//    Server server;
    Client client;

    string name;

private:
    int m_socket;
    struct sockaddr_in m_address;
    struct sockaddr_in m_peerAddress;


};

#endif // XNODE_H
