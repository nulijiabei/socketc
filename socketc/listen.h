#ifndef LISTEN_H
#define LISTEN_H

#include <string>
#include <netinet/in.h>
#include <ev.h>

using namespace std;
class Listen
{
public:
    Listen(int _port);
public:
    int tcp();
    int udp();
    int accepts(void(*func)(struct ev_loop*, struct ev_io*, int));
private:
    // 要监听的端口
    int port;
    // 描述符
    int sockfd;
    // Loop
    struct ev_loop *loop;
};

#endif // LISTEN_H
