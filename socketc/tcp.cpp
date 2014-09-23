#include "tcp.h"
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

/*

    ### 使用方法 ###

    int func(int sockfd){
        return 0;
    }

    int main()
    {
        Tcp * tcp = new Tcp("192.168.0.1", 8080);
        tcp->conn();
        tcp->rw(func);
        return 0;
    }

*/

Tcp::Tcp(string _addr, int _port)
{
    addr = _addr;
    port = _port;
}

int Tcp::conn()
{
    // 地址结构
    struct sockaddr_in address;
    // 初始化变量
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
    if(connect(sockfd, (struct sockaddr*) &address, sizeof(address)) < 0)
    {
        return -1;
    }
    // 返回
    return sockfd;
}

// 闭包使用
int Tcp::rw(int(*func)(int))
{
    // 执行
    return func(sockfd);
}
