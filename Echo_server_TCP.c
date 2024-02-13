//Program to demonstrate connection-oriented (TCP) Echo service using user-defined port
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
main(int argc,char *argv[])
{
	int sid,sid1,rval;
	struct sockaddr_in s,c;
	int clen;
	char buffer[20];
	system("clear");
	if(argc<3)
	{
		printf("\nUSAGE:%s IP_ADDRESS PORT #\n",argv[0]);
		exit(0);
	}
	sid=socket(AF_INET,SOCK_STREAM,0);
	if(sid==-1)
	{
		perror("SOCK-CRE-ERR:");
		exit(1);
	}
	printf("\nSocket created successfully");
	s.sin_family=AF_INET;
	s.sin_addr.s_addr=inet_addr(argv[1]);
	s.sin_port=htons(atoi(argv[2]));
	rval=bind(sid,(struct sockaddr*)&s,sizeof(s));
	if(rval==-1)
	{
		perror("BIND-ERR:");
		close(sid);
		exit(1);
	}
	printf("\nBinded successfully");
	rval=listen(sid,5);
	if(rval==-1)
	{
		perror("LISTEN-ERR:");
		close(sid);
		exit(1);
	}
	printf("\nListening....");
	clen=sizeof(c);
	sid1=accept(sid,(struct sockaddr*)&c,&clen);
	rval=recv(sid1,buffer,sizeof(buffer),0);
	if(rval==-1)
	{
		perror("MSG-RCV-ERR:");
		exit(1);
	}
	printf("\nClient request is %s\n",buffer);
	strcat(buffer," Abraar ");
	rval=send(sid1,buffer,sizeof(buffer),0);
	if(rval==-1)
	{
		perror("MSG-SND-ERR:");
		exit(1);
	}
	printf("Response sent\n");
	close(sid);
	close(sid1);
}

