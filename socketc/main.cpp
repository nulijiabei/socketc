#include <iostream>
#include <listen.h>
#include <arpa/inet.h>
#include <tcp.h>

using namespace std;


int func(int sockfd){
    return 0;
}

int main()
{
    Tcp * tcp = new Tcp("192.168.0.1", 8080);
    cout << tcp->conn() << endl;
    cout << tcp->rw(func) << endl;
    return 0;
}

