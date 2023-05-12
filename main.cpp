#include <iostream>
#include "xnode.h"
#include <thread>
#include "message.h"

using namespace std;


int main(int argc, char* argv[])
{
    //    std::cout << std::setw(4) << json::meta() << std::endl;

    XNode node;


    if(string(argv[1]) == "listen") {

        thread server_thread(&XNode::service, &node, atoi(argv[2]));
        server_thread.detach();

    } else if(string(argv[1]) == "connect") {

        string cmd = R"(
            {
            "group": [
                {"ip":"127.0.0.1", "port": 10000},
                {"ip":"127.0.0.1", "port": 10001},
                {"ip":"127.0.0.1", "port": 10002}
            ],
                "times": 10,
                "interval": 1000,
                "content": "hello world"
            }
        )";
        auto c = json::parse(cmd);
        //    cout<<json::parse(cmd).dump(4)<<endl;

        vector<thread*> clients;

        cout<<c["content"]<<endl;
        for(auto group : c["group"]) {
            cout<<group["ip"]<<"\t"<<group["port"]<<endl;
            thread* client = new thread(&XNode::contact, &node, group["ip"], group["port"]);
            client->detach();
            sleep(5);
            clients.push_back(client);
        }
    }
    //    if(argc > 4 && argc <= 6) {
    //        thread client_thread(&XNode::contact, &node, argv[4], atoi(argv[5]));
    //        client_thread.detach();
    //    }


    //    for(const auto &client : node.clients) {
    //        thread client_thread(&XNode::contact, &node);
    //        client_thread.detach();
    //    }

    sleep(600);


    return 0;
}
