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
    // 创建
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        return -1;
    }
    // 返回
    return sockfd;
}

int Udp::sendtos(int(*func)(int, struct sockaddr*, socklen_t))
{
    // 地址
    sockaddr_in address;
    // 长度
    socklen_t address_len = sizeof(address);
    // 初始化
    bzero(&address, sizeof(address));
    // 设置
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = inet_addr(addr.c_str());
    // 执行
    return func(sockfd, (sockaddr*) &address, address_len);
}

int Udp::discon()
{
    return close(sockfd);
}

