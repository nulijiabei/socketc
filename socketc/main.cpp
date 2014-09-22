#include <iostream>
#include <listen.h>
#include <arpa/inet.h>

using namespace std;


// read sokcet descriptor
void func(struct ev_loop * _loop, struct ev_io * _watcher, int _revents){
    // 错误处理
    if(EV_ERROR & _revents)
    {
        return;
    }
    // 描述符信息
    struct stat s_info;
    fstat(_watcher->fd, &s_info);
    cout << (long) s_info.st_ino << endl;
}

int main()
{
    cout << "Hello World!" << endl;
    Listen * listen = new Listen(8080);
    cout << "TCP ->" << listen->tcp() << endl;
    listen->accepts(func);
    return 0;
}

