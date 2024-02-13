#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>
int main()
{
	int sockfd,x,c,n;
	char buff[1000],buff1[1000];
	struct sockaddr_in se,cli;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("Socket not created\n");
		exit(0);
	}
	printf("Socket created\n");
	se.sin_family=AF_INET;
	se.sin_port=htons(8068);
	se.sin_addr.s_addr=inet_addr("10.2.0.9");
	c=connect(sockfd,(struct sockaddr*)&se,sizeof(se));
	if(c==-1)
		printf("Connection not established\n");
	printf("Connection established\n");
	while(1)
	{
		bzero(&buff1,sizeof(buff1));
		printf("%s","Enter the input data : ");
		fgets(buff1,10000,stdin);
		send(sockfd,buff1,strlen(buff1)+1,0);
		printf("%s\n","Data sent");
		n=1;
		while(n==1)
		{
			bzero(&buff,sizeof(buff));
			recv(sockfd,buff,sizeof(buff),0);
			printf("Received from the server: %s\n",buff);
			n=n+1;
		}
	}
	close(sockfd);
}


