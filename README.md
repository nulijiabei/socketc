-----------------------------------  
开放连接方式(socket)封装，C++

-----------------------------------  
Listen TCP 

	// 基于TCP的监听，引入libev进行多事件处理
	void func(struct ev_loop * loop, struct ev_io * watcher, int revents){
		// 错误处理
		if(EV_ERROR & revents)
		{
			return;
		}
		// 连接
		watcher->fd
	}

	int main()
	{
		Listen * listen = new Listen(8080);
		listen->tcp(); // -1 Error
		listen->accepts(func); // Thread Loop
		return 0;
	}

-----------------------------------  
Listen UDP

	// 基于UDP的监听，通过函数指针进行封装处理
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
		Listen * listen = new Listen(55601);
		listen->udp(); // -1 Error
		listen->recvfroms(func); // -1 Error
		return 0;
	}

-----------------------------------  
TCP

	// 基于TCP的连接，通过函数指针进行封装处理
	int func(int sockfd){
		return 0;
		// return -1; // -1 Error
	}

	int main()
	{
		Tcp * tcp = new Tcp("192.168.0.1", 8080);
		tcp->conn(); // -1 Error
		tcp->rw(func); // -1 Error
		tcp->discon(); // -1 Error
		return 0;
	}

-----------------------------------  
UDP

	// 基于UDP的链接，通过函数指针进行封装处理
	int func(int sockfd, struct sockaddr_in* address, socklen_t address_len){
		string buf = "hello world!";
		sendto(sockfd, buf.c_str(), buf.length(), 0, (sockaddr*) address, address_len);
		return 0;
		// return -1; // -1 Error
	}

	int main()
	{
		// "192.168.0.1"     指定连接
		// "192.168.0.255"   网段广播
		// "255.255.255.255" 全网广播
		Udp * udp = new Udp("255.255.255.255", 55601);
		udp->udp(); // -1 Error
		udp->sendtos(func); // -1 Error
		udp->discon(); // -1 Error
		return 0;
	}

