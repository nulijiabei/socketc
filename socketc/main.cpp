#include <iostream>
#include <listen.h>
#include <arpa/inet.h>
#include <tcp.h>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <string.h>


using namespace std;


int func(int sockfd){
    while(true)
    {
        sockaddr_in address;
        socklen_t address_len = sizeof(address);
        char buf[1024];
        int i = recvfrom(sockfd, buf, 1024, 0, (sockaddr*) &address, &address_len);
        cout << inet_ntoa(address.sin_addr) <<  address.sin_port << endl;
    }
    return 0;
}

int main()
{
    Listen * listen = new Listen(55601);
    listen->udp(func);
    return 0;
}

