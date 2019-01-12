#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define MAXLINE 4096
#define PORT 8000

int main(void){
	int listen_fd = -1,connect_fd = -1;
	struct sockaddr_in servaddr;
	char sendbuf[MAXLINE],recbuf[MAXLINE];

	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;//IPv4
	servaddr.sin_port = htons(8000);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if((listen_fd = socket(AF_INET,SOCK_STREAM,0)) == -1){
	
		printf("creat socket error:%s(error:%d)\n",strerror(errno),errno);
		exit(0);
	}
	if(bind(listen_fd,(struct sockaddr*)&servaddr,sizeof(servaddr)) == -1){
		printf("bind socket error :%s(error:%d)\n",strerror(errno),errno);
		exit(0);
	}
	if(listen(listen_fd,10) == -1){
		printf("listen socket error:%s(error:%d)\n",strerror(errno),errno);
		exit(0);
	}
	printf("wait for client linking...\n");
	while(1){
		if((connect_fd = accept(listen_fd,(struct sockaddr*)NULL,NULL)) == -1){
			printf("accept socket error:%s(error:%d)\n",strerror(errno),errno);
			continue;
		}
		while(1){
			ssize_t len = read(connect_fd,recbuf,sizeof(recbuf));
			if(len < 0){
			if(errno == EINTR){
				continue;
				}
				exit(0);
		}
		printf("receive client's requestion: %s\n",recbuf);

		printf("response client's infomations: ");
		fgets(sendbuf,sizeof(sendbuf),stdin);
		write(connect_fd,sendbuf,sizeof(sendbuf));
	}

		close(connect_fd);
	}
	close(listen_fd);
}

