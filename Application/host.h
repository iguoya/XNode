#ifndef HOST_H
#define HOST_H

//#include <QObject>
#include <map>
#include <string>
using namespace std;

struct HostInfo {
    string ip;
    uint16_t port;
};

class Host
{
public:
    Host();
    map<string, HostInfo> getHosts();
private:
    map<string, HostInfo> hosts;

};

#endif // HOST_H
