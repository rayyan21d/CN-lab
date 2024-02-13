#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
main(int argc,char* argv[])
{
	int sockid,rval,clen;
	char buffer[20];
	struct sockaddr_in s,c;
	if(argc<3)
	{
	  printf("\nUsage:%s IP_ADDRESS PORT#\n");
	  exit(0);
	}
	sockid=socket(AF_INET,SOCK_DGRAM,0);
	if(sockid==-1)
	{
          perror("SOCK_CRE_ERR");
	  exit(1);
	}
	s.sin_family=AF_INET;
	s.sin_addr.s_addr=inet_addr(argv[1]);
  	s.sin_port=htons(atoi(argv[2]));
	printf("Socket creted\n");
	rval=bind(sockid,(struct sockaddr*)&s,sizeof(s));
	if(rval==-1)
	{
	   perror("BIND_ERR");
	   close(sockid);
	   exit(1);
	}
	printf("Socket binded\n");
	clen=sizeof(c);
	rval=recvfrom(sockid,buffer,sizeof(buffer),0,(struct sockaddr*)&c,&clen);
	if(rval==-1)
	{
	  perror("MSG_RCV_ERR:");
	}
	else
	{
	  printf("\nRequest received\n Request message is :%s\n",buffer);
	}
	rval=sendto(sockid,buffer,sizeof(buffer),0,(struct sockaddr*)&c,sizeof(c));
	if(rval==-1)
	{
	  perror("MSG-SND-ERR:");
	}
	else
	{
	  printf("\nResponse sent successfully");
	}
	close(sockid);
}


