#include <iostream>
#include <listen.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    Listen * listen = new Listen(8080);
    cout << "TCP ->" << listen->tcp() << endl;
    while(true)
    {
        sockaddr_in client_addr;
        int c = listen->accepts(&client_addr);
        cout << c << endl;
        cout << client_addr.sin_port << endl;
        cout << inet_ntoa(client_addr.sin_addr) << endl;
    }
    return 0;
}

