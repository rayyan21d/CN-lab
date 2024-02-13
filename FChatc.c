//Full duplex (client)
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<strings.h>
#include<string.h>
int main()
{
	int sockfd,x,c,n,pid;
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
	se.sin_port=htons(5054);
	se.sin_addr.s_addr=inet_addr("10.2.0.9");
	c=connect(sockfd,(struct sockaddr *)&se,sizeof(se));
	if(c==-1)
	{
		printf("Connection not established\n");
		exit(0);
	}
	printf("Connection Established\n");
	pid=fork();
	if(pid==0)
	{
		while(1)
		{
			bzero(&buff1,sizeof(buff1));
			printf("Enter the input data: ");
			fgets(buff1,10000,stdin);
			send(sockfd,buff1,strlen(buff1)+1,0);
			printf("Data sent\n");
		}
	}
	else
	{
		while(1)
		{
			bzero(&buff,sizeof(buff));
			recv(sockfd,buff,sizeof(buff),0);
			printf("\nReceived from the server:%s\n",buff);
		}
	}
	close(sockfd);
}
