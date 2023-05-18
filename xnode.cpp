#include "xnode.h"

size_t XNode::serialNumber;

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

        cout<<buffer<<endl;

        printf("client send:%s\n", buffer);  //打印client发过来的信息

        string ss(buffer);
        if(ss.find("type") == string::npos) {

        } else {
            json command = json::parse(buffer);

            if(!command.contains("type")) {
                continue;
            }
            if(command["type"] == "contact") {


                vector<string> greets {R"({"content":"hello B","id":1,"receiver":"B","sender":"A","sequence":0,"time":"20230518104418_568"})",
                                       R"({"content":"hello C","id":2,"receiver":"C","sender":"A","sequence":0,"time":"20230518104418_568"})",
                                       R"({"content":"hello D","id":2,"receiver":"D","sender":"A","sequence":0,"time":"20230518104418_568"})"};
                int i = 0;
                for(auto server: command["contacts"]) {

                    cout<<server["ip"]<<server["port"]<<endl;
                    Client* client = new Client;
                    client->connect(server["ip"], server["port"]);
                    client->receiver = server["name"];
//                    reporter.send(name+" 跟节点"+client->receiver+"建立连接，打招呼："+greets[i]);
                    reporter.send(greets[i]);
                    client->send(greets[i]);
                    clients.push_back(client);
                    ++i;
                }
            } else if(command["type"] == "send") {


                for(auto i = 0; i < command["times"]; ++i) {
                    for(auto client: clients) {
                        ++serialNumber;

                        json message;
                        message["id"] = serialNumber;
                        message["type"] = "message";
                        message["sender"] = name;
                        message["receiver"] = client->receiver;
                        message["sequence"] = i+1;
                        message["time"] = getCurrentTime();
                        message["content"] = command["content"];



                        client->send(message.dump());
                        reporter.send(message.dump());



                        usleep(command["interval"].get<uint64_t>()*1000);
                    }
                }
                //            clients[1]->run(R"({"type":"hello!!!!"})");
                //            cout<<clients.size()<<endl;
            }

        }




        //        memset(buffer, 0, buffer_length);
        //        sprintf(buffer, "server: I have recieved %d bytes data!\n", count);  //回复client
        //        printf("server response:%s\n", buffer);  //打印自己发送的信息给
        //        sendto(m_socket, buffer, buffer_length, 0, (struct sockaddr*)&client_address, length);  //发送信息给client，注意使用了clent_addr结构体指针
    }
}

string XNode::getCurrentTime()
{
    string defaultTime = "19700101000000000";
    try
    {
        struct timeval curTime;
        gettimeofday(&curTime, NULL);
        int milli = curTime.tv_usec / 1000;

        char buffer[80] = {0};
        struct tm nowTime;
        localtime_r(&curTime.tv_sec, &nowTime);//把得到的值存入临时分配的内存中，线程安全
        strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S", &nowTime);

        char currentTime[84] = {0};
        snprintf(currentTime, sizeof(currentTime), "%s_%03d", buffer, milli);

        return currentTime;
    }
    catch (...)
    {
        return defaultTime;
    }
}


