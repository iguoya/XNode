#include "host.h"

Host::Host()
{
    hosts = {
        {
            "A", {"127.0.0.1", 10000}
        },
        {
            "B", {"127.0.0.1", 10001}
        },
        {
            "C", {"127.0.0.1", 10002}
        },
        {
            "D", {"127.0.0.1", 10003}
        }
    };
}

map<string, HostInfo> Host::getHosts()
{
    return hosts;
}

