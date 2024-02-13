#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<strings.h>
#include<string.h>
int main()
{
	int sockfd,l,b,a,x,n;
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
	b=bind(sockfd,(struct sockaddr*)&se,sizeof(se));
	if(b==-1)
	{
		printf("Not binded\n");
		exit(0);
	}
	printf("Binded\n");
	l=listen(sockfd,5);
	if(l==-1)
	{
		printf("Not listening\n");
	}
	printf("Listening\n");
	for(;;)
	{
		x=sizeof(cli);
		a=accept(sockfd,(struct sockaddr*)&cli,&x);
		if(a==-1)
			printf("Not accepting");
		printf("Accepting\n");
		while(1)
		{
			bzero(&buff,sizeof(buff));
			recv(a,buff,sizeof(buff),0);
			printf("Receive from the client:%s\n",buff);
			n=1;
			while(n==1)
			{
				bzero(&buff1,sizeof(buff1));
				printf("%s\n","Enter the input data :");
				fgets(buff1,10000,stdin);
				send(a,buff1,strlen(buff1)+1,0);
				printf("%s\n","Data sent");
				n=n+1;
			}
		}
	}
	close(a);
	close(sockfd);
}
		
