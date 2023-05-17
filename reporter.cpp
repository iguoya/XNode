#include "reporter.h"

Reporter::Reporter()
{
    m_socket = socket(PF_INET, SOCK_DGRAM, 0);
    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    m_address.sin_port = htons(8888);
}

Reporter::~Reporter()
{
    close(m_socket);
}

void Reporter::send(string s)
{

    //    char buffer[1024] = {0};
    //    json j={
    //        {"name","LeBorn Jame"},
    //        {"number",23},
    //        {"children",{"LeBorn Jr","Bryce Maximus","Zhuri"}},
    //        {"man",true},
    //        {"wife",{"name","Savannah Brinson"}}
    //    };

    socklen_t addr_len = sizeof(m_address);
    //    string s(j.dump().c_str());
    //    cout<<s<<endl;

    //    memcpy(buffer, s.c_str(), s.size());
    //    printf("client:%s\n", buffer);  //打印自己发送的信息
    //    sendto(m_socket, buffer, sizeof(buffer), 0, (struct sockaddr *)&m_address, addr_len);

    cout<<s<<endl;
    sendto(m_socket, s.c_str(), s.size(), 0, (struct sockaddr *)&m_address, addr_len);


    //    recvfrom(m_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)&server_address, &addr_len);  //接收来自server的信息
    //    printf("server:%s\n", buffer);
    //    sleep(2);  //一秒发送一次消息
    //    }


    //    for(auto i = 0; i < 10; ++i) {
    //        request(generateMessage());
    //        usleep(100000);
    //        response();
    //    }
    //    writeLog(m_name+"_sendLog.txt");
    //    writeLog(m_name+"_receiveLog.txt");
}
