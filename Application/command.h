#ifndef COMMAND_H
#define COMMAND_H

#include "host.h"
#include <string>
#include <vector>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using namespace std;

class Command
{
public:
    Command();

    string contact(string client, vector<string> servers);

    string send_message(string msg, size_t times = 10000, size_t interval = 1000);


private:
    map<string, pair<string, uint16_t>> hosts;
};

#endif // COMMAND_H
