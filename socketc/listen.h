#ifndef LISTEN_H
#define LISTEN_H

#include <string>
#include <netinet/in.h>

using namespace std;
class Listen
{
public:
    Listen(int _port);
    ~Listen();
public:
    int tcp();
    int udp();
    int accepts(sockaddr_in * _client_addr, socklen_t * _client_addr_len);
private:
    // 要监听的端口
    int port;
    // 描述符
    int sockfd;
};

#endif // LISTEN_H
