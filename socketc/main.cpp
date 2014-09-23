#include <iostream>
#include <listen.h>
#include <arpa/inet.h>
#include <tcp.h>

using namespace std;


int func(int sockfd){
    string a = "123#End\n";
    send(sockfd, a.c_str(), sizeof(a.c_str()), 0);
    cout << a << endl;
    return 0;
}

// run
int main()
{
    Tcp * tcp = new Tcp("192.168.2.150", 8700);
    cout << tcp->conn() << endl;
    cout << tcp->rw(func) << endl;
    return 0;
}

