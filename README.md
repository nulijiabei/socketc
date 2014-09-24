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
		listen->tcp(); // -1 Error
		listen->accepts(func); // Thread Loop
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

	int func(int sockfd, struct sockaddr* _address, socklen_t _address_len)
	{
		string buf = "hello world!";
		sendto(sockfd, buf.c_str(), buf.length(), 0, _address, _address_len);
		return 0;
		// return -1; // -1 Error
	}

	int main()
	{
		Udp * udp = new Udp("192.168.0.255", 55601);
		udp->udp(); // -1 Error
		udp->sendtos(func); // -1 Error
		return 0;
	}


