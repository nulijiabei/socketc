#include "udp.h"
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

Udp::Udp(string _addr, int _port)
{
    addr = _addr;
    port = _port;
}

int Udp::udp()
{
    // 用来绑定套接字
    sockaddr_in address;
    // 初始化
    bzero(&address, sizeof(address));
    // 设置
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_BROADCAST;
    // 创建
    if((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        return -1;
    }
    // 标识赋值
    if (bind(sockfd, (sockaddr*) &address, sizeof(address)) != 0)
    {
        close(sockfd);
        return -1;
    }
    // 返回
    return sockfd;
}

int Udp::sendtos(int(*func)(int))
{
    return func(sockfd);
}

int Udp::discon()
{
    return close(sockfd);
}

