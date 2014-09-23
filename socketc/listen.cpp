#include "listen.h"
#include <string.h>
#include <unistd.h>
#include <ev.h>
#include <iostream>

/*

    ### 使用方法（TCP） ###

    // read sokcet descriptor
    void func(struct ev_loop * _loop, struct ev_io * _watcher, int _revents){
        // 错误处理
        if(EV_ERROR & _revents)
        {
            return;
        }
        // 连接
        watcher->fd
    }

    // run
    int main()
    {
        Listen * listen = new Listen(8080);
        listen->tcp();
        listen->accepts(func);
        return 0;
    }

    ### 使用方法（UDP） ###

    int func(int sockfd, struct sockaddr_in * address){
        while(true)
        {
            char buf[32];
            socklen_t address_len = sizeof(address);
            recvfrom(sockfd, buf, 32, 0, (sockaddr*) address, &address_len);
            cout << buf << endl;
        }
        return 0;
    }

    int main()
    {
        Listen * listen = new Listen(55601);
        listen->udp(func);
        return 0;
    }

*/

Listen::Listen(int _port)
{
    port = _port;
    loop = ev_default_loop(0);
}

int Listen::tcp()
{
    // 地址结构
    sockaddr_in address;
    // 初始化
    bzero(&address, sizeof(address));
    // 地址族
    address.sin_family = AF_INET;
    // 必须要采用网络数据格式,普通数字可以用htons()函数转换成网络数据格式的数字
    address.sin_port = htons(port);
    // IP,地址结构,INADDR_ANY,就是指定地址为0.0.0.0的地址
    address.sin_addr.s_addr = INADDR_ANY;
    // 创建
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        return -1;
    }
    // 标识赋值
    if (bind(sockfd, (sockaddr*) &address, sizeof(address)) != 0)
    {
        close(sockfd);
        return -1;
    }
    // 监听
    if (listen(sockfd, 5) < 0)
    {
        close(sockfd);
        return -1;
    }
    // 返回
    return sockfd;
}

int Listen::udp(int(*func)(int, struct sockaddr_in*))
{
    // 用来广播地址接收数据
    sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_BROADCAST;
    // 用来绑定套接字
    sockaddr_in sin;
    bzero(&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = 0;
    // 创建
    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        return -1;
    }
    // 标识赋值
    if (bind(sockfd, (sockaddr*) &sin, sizeof(sin)) != 0)
    {
        close(sockfd);
        return -1;
    }
    // 执行(阻塞)
    int status = func(sockfd, &address);
    // 关闭
    close(sockfd);
    // 返回
    return status;
}

int Listen::accepts(void(*func)(struct ev_loop*, struct ev_io*, int))
{
    // 地址结构
    sockaddr_in address;
    // 地址结构长度
    socklen_t address_len = sizeof(address);
    // 循环
    while(true)
    {
        // 初始化
        bzero(&address, sizeof(address));
        // 等待接受连接
        int client_sockfd = accept(sockfd, (sockaddr*) &address, &address_len);
        if (client_sockfd < 0)
        {
            close(sockfd);
            return -1;
        }
        // 分派
        ev_io * event = new(ev_io);
        // 初始化
        ev_io_init(event, func, client_sockfd, EV_IO);
        // 运行监听
        ev_io_start(loop, event);
    }
    // 返回（不应到这里)
    return -1;
}
