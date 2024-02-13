#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/inh.h>
#include<unistd.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>
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
	se.sin_port=htons(8019);
	se.sin_addr.s_addr=inet_addr("10.2.0.9");
	c=connect(sockfd,(struct sockaddr*)&se,sizeof(se));
	if(c==-1)
		printf("Connection not established\n");
	printf("Connection established\n");
	pid=fork();
	if(pid==0)
	{
		while(1)
		{
			bzero(&buff1,sizeof(buff1));
			printf("%s\n","Enter the input data: ");
			fgets(buff1,10000,stdin);
			send(sockfd,buff1,strlen(buff1)+1,0);
			printf("%s\n","Data sent");
		}
		
	
