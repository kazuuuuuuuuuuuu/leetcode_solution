// 十六进制参数 转换为点分十进制串并打印
int main(int argc, char const *argv[])
{
	struct in_addr inaddr; // in nextwork byte order
	unit32_t addr; // in host byte order
	char buf[MAXBUF];

	if(argc !=2)
	{
		fprintf(stderr, "usage: %s <hex number>\n", argv[0]);
		exit(0);
	}

	sscanf(argv[1], "%x", &addr);
	inaddr.s_addr = htonl(addr);

	if(!inet_ntop(AF_INET, &inaddr, buf, MAXBUF))
		unix_error("inet_ntop");
	printf("%s\n", buf);

	return 0;
}

// 将点分十进制参数转换为十六进制数并打印
int main(int argc, char const *argv[])
{
	struct in_addr inaddr; // in nextwork byte order
	int rc; // in host byte order

	// 直接将字符串转为uint32_t 
	rc = inet_pton(AF_INET, argv[1], &inaddr);
	
	// 从网络字节顺序转变为host字节顺序
	printf("0x%x\n", ntohl(inaddr.s_addr));
	return 0;
}

int main(int argc, char const *argv[])
{
	struct sddrinfo *p. *listp, hints;
	struct sockaddr_in *sockp;
	char buf[MAXLINE];
	int rc;

	memset(&hints, 0 ,sizeof(struct sddrinfo));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	if((rc = getaddrinfo(argv[1], NULL, &hints, &listp)) != 0)
	{
		exit(1);
	}

	for(p=listp;p;p=p->ai_next)
	{
		// 将通用套接字地址结构指针 转化为 ip专用套接字地址结构指针
		sockp = (struct sockaddr_in *) p->ai_addr;
		// 用于ip地址的转换 sockp中的sin_addr字段
		inet_ntop(AF_INET, &(sockp->sin_addr), buf, MAXBUF);
		printf("%s\n", buf);
	}

	Freeaddrinfo(listp);
	return 0;
}

// 客户端 调用open_clientfd 建立与服务器的连接
int open_clientfd(char *hostname, char *port)
{
	int clientfd;
	struct addrinfo hints, *listp, *p;

	// get a list of potential server addresses
	memset(&hints, 0 , sizeof(struct sddrinfo));
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_NUMERICSERV;
	hints.ai_flags |= AI_ADDRCONFIG;
	Getaddrinfo(hostname, port, &hints, &listp);

	// walk the list for one that we can successfully connect to
	for(p=listp;i;p=p->ai_next)
	{
		// create a socket descriptor
		if((clientfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
			continue; // failed, try the next

		// connect to the server
		if(connect(clientfd, p->ai_addr, p->addrlen) != -1)
			break; // success

		Close(clientfd);
	}

	Freeaddrinfo(listp);
	if(!p) // p == nullptr
		return -1;
	else
		return clientdf;
}

int open_listenfd(char *port)
{
	struct addrinfo hints, *listp, *p;
	// get a list of potential server addresses
	memset(&hints, 0 , sizeof(struct sddrinfo));
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_NUMERICSERV;
	hints.ai_flags |= AI_PASSIVE | AI_ADDRCONFIG;
	Getaddrinfo(NULL, port, &hints, &listp);	

	// walk the list for one that we can bind to
	for(p = listp;p;p=p->ai_next)
	{
		// create a socket descriptor
		if((listen = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) < 0)
			continue; // socket failed, try the next

		// eliminates address already in use error from bind
		Setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));

		// bind the descriptor to the address
		if(bind(listenfd, p->ai_addr, p->ai_addlrlen) == 0)
			break; // success, break
		Close(listenfd); // bind failed, try the next;
	}

	Freeaddrinfo(listp);
	if(!p) // no address worked
		return -1;

	// make it a listening socket ready to accept connection requests
	if(listen(listenfd, LISTENQ) < 0)
	{
		Close(listenfd);
		return -1;
	}

	return listenfd;

}

// echo 客户端的代码
int int main(int argc, char const *argv[])
{
	int clientfd;
	char *host, *port, buf[MAXLINE];
	rio_t rio;

	host = argv[1];
	port = argv[2];
	clientfd = Open_clientfd(host, port);
	Rio_readinitb(&rio, clientfd);

	while(Fget(buf, MAXLINE, stdin) != NULL)
	{
		Rio_writen(clientfd, buf, strlen(buf));
		Rio_readlineb(&rio, buf, MAXLINE);
		Fputs(buf, stdout);
	}
	Close(clientfd);
	exit(0);
	return 0;
}

// echo 服务器的代码
void echo(int connfd);
int int main(int argc, char const *argv[])
{
	int listenfd, connfd;
	socklen_t clientlen;
	struct sockaddr_storage clientaddr; // enough space for any address
	char client_hostname[MAXLINE], client_port[MAXLINE];

	// 打开一个监听描述符
	listenfd = Open_listenfd(argv[1]);
	while(1)
	{
		clientlen = sizeof(struct sockaddr_storage);
		connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
		Getnameinfo((SA *) &clientaddr, clientlen, client_hostname, MAXLINE, client_port, MAXLINE, 0);
		printf("connected to (%s, %s)\n", client_hostname, client_port);
		echo(connfd);
		Close(connfd);
	}
	exit(0);
}

void echo(int connfd)
{
	size_t n;
	char buf[MAXLINE];
	rio_t rio;

	Rio_readinitb(&rio, connfd);
	while((n = Rio_readlineb(&rio, buf, MAXLINE)) != 0)
	{
		printf("server received %d bytes\n", (int)n);
		Rio_writen(connfd, buf, b);
	}
}