#include <iostream>
#include <listen.h>
#include <arpa/inet.h>
#include <tcp.h>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <string.h>
#include <udp.h>


using namespace std;

int func(int sockfd)
{
    sockaddr_in address;
    socklen_t address_len = sizeof(address);
    char buf[1024];
    while(true)
    {
        int i = recvfrom(sockfd, buf, 1024, 0, (sockaddr*) &address, &address_len);
        cout << inet_ntoa(address.sin_addr) <<  address.sin_port << endl;
    }
    return 0;
    return -1; // -1 Error
}

int main()
{
    Listen * listen = new Listen(8888);
    listen->udp(func); // -1 Error
    return 0;
}

/*
int func(int sockfd){
    while(true)
    {
        sockaddr_in address;
        socklen_t address_len = sizeof(address);
        // 初始化
        bzero(&address, sizeof(address));
        // 设置
        address.sin_family = AF_INET;
        address.sin_port = htons(8888);
        address.sin_addr.s_addr = INADDR_BROADCAST;
        string buf = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        sendto(sockfd, buf.c_str(), 1024, 0, (sockaddr*) &address, address_len);
    }
    return 0;
}

int main()
{
    Udp * udp = new Udp("0", 8888);
    udp->udp();
    udp->sendtos(func);
    return 0;
}
*/


