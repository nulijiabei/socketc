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

/*
int func(int sockfd, struct sockaddr_in* address, socklen_t address_len)
{
    char buf[1024];
    while(true)
    {
        int i = recvfrom(sockfd, buf, 1024, 0, (sockaddr*) address, &address_len);
        cout << inet_ntoa(address->sin_addr) << endl;
        cout << buf << endl;
    }
    return 0;
    // return -1; // -1 Error
}


int main()
{
    cout << "is listen" << endl;
    Listen * listen = new Listen(55601);
    listen->udp(); // -1 Error
    listen->recvfroms(func); // -1 Error
    return 0;
}
*/



int func(int sockfd, struct sockaddr_in* address, socklen_t address_len){
    string buf = "hello world!";
    int st = sendto(sockfd, buf.c_str(), buf.length(), 0, (sockaddr*) address, address_len);
    cout << st << endl;
    return 0;
}

int main()
{
    cout << "is sends" << endl;
    Udp * udp = new Udp("192.168.2.255", 55601);
    udp->udp();
    udp->sendtos(func);
    return 0;
}


