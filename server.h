#ifndef SERVER_H
#define SERVER_H



using namespace std;

class Server
{
public:
    Server();

    void listen(uint16_t port);
    void run();

    ~Server();

private:
    int m_socket;
    struct sockaddr_in m_address;
    struct sockaddr_in m_peerAddress;
};

#endif // SERVER_H
