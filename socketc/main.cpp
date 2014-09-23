#include <iostream>
#include <listen.h>
#include <arpa/inet.h>
#include <tcp.h>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <string.h>


using namespace std;


int func(int sockfd, struct sockaddr_in * address){
    while(true)
    {
        cout << "1" << endl;
        char buf[32];
        socklen_t address_len = sizeof(address);
        recvfrom(sockfd, buf, 32, 0, (sockaddr*) address, &address_len);
        cout << "2" << endl;
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

