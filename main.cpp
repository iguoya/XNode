#include <iostream>
#include "xnode.h"
#include <thread>
#include "message.h"

using namespace std;

int main(int argc, char* argv[])
{
    //    std::cout << std::setw(4) << json::meta() << std::endl;

    XNode node;



    thread server_thread(node, argv[1], atoi(argv[2]));
    server_thread.join();






    return 0;
}
