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
    // 开启广播
    int broadcast = 1;
    // 设置
    if(setsockopt(sockfd,SOL_SOCKET,SO_BROADCAST,&broadcast,sizeof(broadcast)) == -1)
    {
        return -1;
    }
    // 返回
    return sockfd;
}

int Udp::sendtos(int(*func)(int, struct sockaddr_in*, socklen_t))
{
    // 广播地址
    string broadcast = "255.255.255.255";
    // 地址
    sockaddr_in address;
    // 长度
    socklen_t address_len = sizeof(address);
    // 初始化
    bzero(&address, sizeof(address));
    // 设置
    address.sin_family = AF_INET;
    // 端口
    address.sin_port = htons(port);
    // 判断类型
    if(strcmp(addr.c_str(), broadcast.c_str()) == 0)
    {
        address.sin_addr.s_addr = INADDR_BROADCAST;
    }
    else
    {
        address.sin_addr.s_addr = inet_addr(addr.c_str());
    }
    // 执行
    return func(sockfd, &address, address_len);
}


int Udp::discon()
{
    return close(sockfd);
}

