#include "listen.h"
#include <string.h>
#include <unistd.h>
#include <ev.h>
#include <iostream>

/*

    ### 使用方法 ###

    // read sokcet descriptor
    void func(struct ev_loop * _loop, struct ev_io * _watcher, int _revents){
        // 错误处理
        if(EV_ERROR & _revents)
        {
            return;
        }
    }

    // run
    int main()
    {
        Listen * listen = new Listen(8080);
        listen->tcp();
        listen->accepts(func);
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
    struct sockaddr_in address;
    // 初始化变量
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
    if (bind(sockfd, (struct sockaddr*) &address, sizeof(address)) != 0)
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

int Listen::udp()
{
    // 暂未实现
    return -1;
}

int Listen::accepts(void(*func)(struct ev_loop*, struct ev_io*, int))
{
    // 地址结构
    sockaddr_in client_addr;
    // 地址结构长度
    socklen_t client_addr_len = sizeof(client_addr);
    // 循环
    while(true)
    {
        // 初始化变量
        bzero(&client_addr, sizeof(client_addr));
        // 等待接受连接
        int client_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sockfd < 0)
        {
            close(sockfd);
            return -1;
        }
        // 分派
        ev_io * event = new(ev_io);
        // 开始监听事件
        ev_io_init(event, func, client_sockfd, EV_IO);
        ev_io_start(loop, event);
    }
    return -1;
}
