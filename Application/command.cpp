#include "command.h"

Command::Command()
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

string Command::contact(string client, vector<string> servers)
{
    json j;
    j["type"] = "contact";
    j["executor"]["ip"] = hosts[client].first;
    j["executor"]["port"] = hosts[client].second;

    for(auto i = 0; i < servers.size(); ++i) {
        j["contacts"][i]["ip"] = hosts[servers[i]].first;
        j["contacts"][i]["port"] = hosts[servers[i]].second;
    }

    return j.dump();
}

string Command::send_message(string msg, size_t times, size_t interval)
{
    json j;
    j["type"] = "send";
    j["message"] = json::parse(msg);
    j["times"] = times;
    j["interval"] = interval;
    return j.dump();
}
