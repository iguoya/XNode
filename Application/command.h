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
private:
    map<string, pair<string, uint16_t>> hosts;
};

#endif // COMMAND_H
