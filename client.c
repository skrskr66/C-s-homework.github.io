#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<errno.h>
#include<unistd.h>

#define MAXLINE 4096
#define PORT 8000
int main(void){
	int sockfd = -1;
	struct sockaddr_in servaddr;
	char sendbuf[MAXLINE],recbuf[MAXLINE];
	memset(&servaddr,0,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1){
		printf("create socket error:%s(error:%d)\n",strerror(errno),errno);
		exit(0);
	}
	if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) == -1){
		printf("connect socket error:%s(error:%d)\n",strerror(errno),errno);
		exit(0);
	}
	while(1){
		printf("please send message:");
		fgets(sendbuf,sizeof(sendbuf),stdin);
		write(sockfd,sendbuf,sizeof(sendbuf));

		ssize_t len = read(sockfd,recbuf,sizeof(recbuf));
		if (len < 0){
			if(errno == EINTR){
				continue;
			}
			exit(0);
		}
		printf("server response:%s\n",recbuf);
		
	}
	
	close(sockfd);


}

