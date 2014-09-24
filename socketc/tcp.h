#ifndef TCP_H
#define TCP_H

#include <string>

using namespace std;
class Tcp
{
public:
    Tcp(string _addr, int _port);
public:
    int conn();
    int discon();
    int rw(int(*func)(int));
private:
    // 地址
    string addr;
    // 端口
    int port;
    // 描述符
    int sockfd;
};

#endif // TCP_H
