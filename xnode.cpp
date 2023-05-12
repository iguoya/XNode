#include "xnode.h"

XNode::XNode()
{
    m_socket = socket(PF_INET, SOCK_DGRAM, 0);
}

XNode::~XNode()
{
    close(m_socket);
}


void XNode::listen(uint16_t port)
{
    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = htonl(INADDR_ANY);
    m_address.sin_port = htons(port);

//    char msg[30] = {0};
//    sprintf(msg, "监听 %d 端口 .....\n", port);
    cout<< "服务器名字:"<< name<<", 监听端口: "<<port<<endl;
    bind(m_socket, (struct sockaddr *)&m_address, sizeof(m_address));
}

void XNode::operator()(string name, uint16_t port)
{
    this->name = name;
    listen(port);
    while(1) {
        struct sockaddr_in client_address;
        char buffer[1024] = {0};  //接收缓冲区，1024字节
        size_t buffer_length = sizeof(buffer);
        socklen_t length = sizeof(client_address);
        int count = recvfrom(m_socket, buffer, buffer_length, 0, (struct sockaddr*)&client_address, &length);  //recvfrom是拥塞函数，没有数据就一直拥塞

        json command = json::parse(buffer);

        cout<<command["type"]<<endl;
        if(command["type"] == "contact") {

//                    string cmd = R"(
//                        {
//                        "group": [
//                            {"ip":"127.0.0.1", "port": 10000},
//                            {"ip":"127.0.0.1", "port": 10001},
//                            {"ip":"127.0.0.1", "port": 10002}
//                        ],
//                            "times": 10,
//                            "interval": 1000,
//                            "content": "hello world"
//                        }
//                    )";
//                    auto c = json::parse(cmd);
                    //    cout<<json::parse(cmd).dump(4)<<endl;
                    //cout<<c["content"]<<endl;



//                    for(auto group : c["group"]) {
//                        cout<<group["ip"]<<"\t"<<group["port"]<<endl;
//                        thread client_connect(&XNode::contact, &node, group["ip"], group["port"]);
//                        client_connect.detach();
//                        sleep(3);
            //            thread* client = new thread(&XNode::contact, &node, group["ip"], group["port"]);
            //            client->detach();
            //            sleep(5);
            //            clients.push_back(client);
                    }
                }

        }


        printf("client send:%s\n", buffer);  //打印client发过来的信息



        memset(buffer, 0, buffer_length);

        sprintf(buffer, "server: I have recieved %d bytes data!\n", count);  //回复client
        printf("server response:%s\n", buffer);  //打印自己发送的信息给
        sendto(m_socket, buffer, buffer_length, 0, (struct sockaddr*)&client_address, length);  //发送信息给client，注意使用了clent_addr结构体指针
    }
}

//void XNode::service(uint16_t port)
//{
//    server.listen(port);
//    server.run();
//}



void XNode::contact(string ip, uint16_t port)
{
    client.connect(ip, port);
    client.run();
}
