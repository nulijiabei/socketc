#ifndef UDP_H
#define UDP_H

#include <string>
#include <netinet/in.h>

using namespace std;

class Udp
{
public:
    Udp(string _addr, int _port);
public:
    int udp();
    int discon();
    int sendtos(int(*func)(int, struct sockaddr_in*, socklen_t));
private:
    // 地址
    string addr;
    // 端口
    int port;
    // 描述符
    int sockfd;
};

#endif // UDP_H
