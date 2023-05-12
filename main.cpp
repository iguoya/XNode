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
    }


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

//    cout<<json::parse(cmd).dump(4)<<endl;
    auto c = json::parse(cmd);

    cout<<c["content"]<<endl;
    for(auto group : c["group"]) {
        cout<<group["ip"]<<"\t"<<group["port"]<<endl;
    }




//    if(argc > 2 && argc <= 4) {
//        thread client_thread(&XNode::contact, &node, argv[2], atoi(argv[3]));
//        client_thread.detach();
//    }


//    if(argc > 4 && argc <= 6) {
//        thread client_thread(&XNode::contact, &node, argv[4], atoi(argv[5]));
//        client_thread.detach();
//    }


    //    for(const auto &client : node.clients) {
    //        thread client_thread(&XNode::contact, &node);
    //        client_thread.detach();
    //    }



    sleep(600);

    //    node.run();

    return 0;
}
