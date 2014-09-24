-----------------------------------  
开放连接方式(socket)封装，C++

-----------------------------------  
Listen TCP

	void func(struct ev_loop * _loop, struct ev_io * _watcher, int _revents){
		// 错误处理
		if(EV_ERROR & _revents)
		{
			return;
		}
		// 连接
		watcher->fd
	}

	int main()
	{
		Listen * listen = new Listen(8080);
		listen->tcp();
		listen->accepts(func);
		return 0;
	}

-----------------------------------  
Listen UDP

	int func(int sockfd)
	{
		sockaddr_in address;
		socklen_t address_len = sizeof(address);
		char buf[1024];			
		while(true)
		{
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

-----------------------------------  
TCP

	int func(int sockfd){
		return 0;
	}

	int main()
	{
		Tcp * tcp = new Tcp("192.168.0.1", 8080);
		tcp->conn();
		tcp->rw(func);
		return 0;
	}

-----------------------------------  
UDP

	TODO
