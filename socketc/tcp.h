#ifndef TCP_H
#define TCP_H

#include <string>

using namespace std;
class Tcp
{
public:
    Tcp(string _addr, int _port);
public:
    void connect();
private:
    // 要监听的地址
    string addr;
    // 要监听的端口
    int port;
    // 最大重试次数
    int maxRetry;
};

#endif // TCP_H
