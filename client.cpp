#include "client.h"


size_t Client::count = 1;

Client::Client()
{
    m_socket = socket(PF_INET, SOCK_DGRAM, 0);
    memset(sendData, 0, sizeof(sendData));
    memset(receiveData, 0, sizeof(receiveData));
}

Client::~Client()
{
    close(m_socket);
}



void Client::connect(string ip, uint16_t port)
{
    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = inet_addr(ip.c_str());
    m_address.sin_port = htons(port);
}

void Client::run(string s)
{
    //    while(true) {
    //        char buffer[1024] = "[\"hello\":\"wrold\"]";

    char buffer[500] = {0};
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

    memcpy(buffer, s.c_str(), s.size());
    printf("client:%s\n", buffer);  //打印自己发送的信息
    sendto(m_socket, buffer, sizeof(buffer), 0, (struct sockaddr *)&m_address, addr_len);
//    memset(buffer, 0, sizeof(buffer));
    recvfrom(m_socket, buffer, sizeof(buffer), 0, (struct sockaddr*)&server_address, &addr_len);  //接收来自server的信息
    printf("server:%s\n", buffer);
    sleep(2);  //一秒发送一次消息
    //    }


    //    for(auto i = 0; i < 10; ++i) {
    //        request(generateMessage());
    //        usleep(100000);
    //        response();
    //    }
    //    writeLog(m_name+"_sendLog.txt");
    //    writeLog(m_name+"_receiveLog.txt");
}

string Client::generateMessage()
{
    int length = 1023;// length: 产生字符串的长度
    char tmp;							// tmp: 暂存一个随机数
    string buffer;						// buffer: 保存返回值

    // 下面这两行比较重要:
    random_device rd;					// 产生一个 std::random_device 对象 rd
    default_random_engine random(rd());	// 用 rd 初始化一个随机数发生器 random

    for (int i = 0; i < length; i++) {
        tmp = random() % 36;	// 随机一个小于 36 的整数，0-9、A-Z 共 36 种字符
        if (tmp < 10) {			// 如果随机数小于 10，变换成一个阿拉伯数字的 ASCII
            tmp += '0';
        } else {				// 否则，变换成一个大写字母的 ASCII
            tmp -= 10;
            tmp += 'A';
        }
        buffer += tmp;
    }
    return buffer;
}


void Client::request(string message)
{
    //    cout<<"向服务器发送请求："<<message<<endl;
    //    Log log(m_name, count);
    //    log.setMessage(message);

    //    strncpy(sendData, message.c_str(), message.size());

    sendto(m_socket, message.c_str(), message.size(), 0, (struct sockaddr *)&m_address, sizeof(m_address));
    //    cout<<"向服务器请求结束："<<endl;
    //    cout<<Log::number<<endl;
    //    cout<<log.time<<endl;
    //    cout<<log.source<<endl;
    //    cout<<log.message<<endl;
    //    sendLogs.push_back(log);

    //    bzero(sendData, sizeof(sendData));
    //    message.clear();

}

void Client::response()
{

    recvfrom(m_socket, receiveData, sizeof(receiveData), 0, NULL, NULL);


    //    cout<<"从服务器接收："<<receiveData<<endl;

    //    Log log("Server", ++count);
    //    log.setMessage(receiveData);
    //    receiveLogs.push_back(log);

    //    bzero(receiveData, sizeof(receiveData));

}

void Client::writeLog(string fileName)
{
    //    ofstream fout;
    //    fout.open(fileName);
    //    for(const auto &log : sendLogs) {
    //        fout<<log.number<<",\t"
    //           <<log.source<<",\t"
    //          <<log.time<<",\t"
    //         <<log.message<<endl;
    //    }
    //    fout.close();
}





