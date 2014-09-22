#include <iostream>
#include <listen.h>
#include <arpa/inet.h>

using namespace std;

//void func(int client_sockfd, sockaddr_in * client_addr)
//{
//    cout << client_addr->sin_port << endl;
//    cout << inet_ntoa(client_addr->sin_addr) << endl;
//}

int main()
{
    cout << "Hello World!" << endl;
//    Listen * listen = new Listen(8080);
//    cout << "TCP ->" << listen->tcp() << endl;
//    listen->accepts(func);
    return 0;
}

