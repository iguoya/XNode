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
#include <sys/time.h>
//#include <linux/delay.h>
#include "reporter.h"
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

private:

    string getCurrentTime();

    static size_t serialNumber;
    vector<Client*> clients;
    Reporter reporter;

    string name;

    int m_socket;
    struct sockaddr_in m_address;
    struct sockaddr_in m_peerAddress;


};

#endif // XNODE_H
