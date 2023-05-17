#ifndef REPORTER_H
#define REPORTER_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;
using namespace std;

class Reporter
{
public:
    Reporter();
    ~Reporter();

    void send(string s);


private:
    int m_socket;
    struct sockaddr_in m_address;
    struct sockaddr_in server_address;

};

#endif // REPORTER_H
