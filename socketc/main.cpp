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
    ifstream inf("/json");
    stringstream in ;
    in << inf.rdbuf() ;
    send(sockfd, in.str().c_str(), strlen(in.str().c_str()), 0);
    ssize_t r_len;
    char buffer[1024];
    bzero(buffer, 1024);
    recv(sockfd, buffer, 1024, 0);
    cout << buffer << endl;
    inf.close();
    return 0;
}

int main()
{
    Tcp * tcp = new Tcp("192.168.2.154", 8700);
    cout << tcp->conn() << endl;
    cout << tcp->rw(func) << endl;
    return 0;
}

