#include "tcp.h"
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

Tcp::Tcp(string _addr, int _port)
{
    addr = _addr;
    port = _port;
}

int Tcp::conn()
{
    // 地址结构
    sockaddr_in address;
    // 初始化
    bzero(&address, sizeof(address));
    // 地址族
    address.sin_family = AF_INET;
    // 设置端口
    address.sin_port = htons(port);
    // 设置地址
    if(inet_aton(addr.c_str(), &address.sin_addr) == 0)
    {
        return -1;
    }
    // 创建
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        return -1;
    }
    // 连接
    if(connect(sockfd, (sockaddr*) &address, sizeof(address)) < 0)
    {
        close(sockfd);
        return -1;
    }
    // 返回
    return sockfd;
}

// 闭包使用
int Tcp::rw(int(*func)(int))
{
    // 执行
    int status = func(sockfd);
    return status;
}

// 断开
int Tcp::discon()
{
   return close(sockfd);
}


