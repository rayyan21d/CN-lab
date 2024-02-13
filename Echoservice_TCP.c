#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
main(int argc,char *argv[])
{
 	 struct sockaddr_in s;
	 int rval,sockid;
	 char m1[20],m2[20];
	 sockid=socket(AF_INET,SOCK_STREAM,0);
	 if(sockid==-1)
 	 {
           perror("SOCK_CRE_ERR:");
           exit(1);
	 }
         system("clear");
	 if(argc<3)
       	 {
  	   printf("\n USAGE : %s IP_ADDRESS PORT#\n",argv[0]);
 	   exit(1);
 	 }
	 s.sin_family=AF_INET;
	 s.sin_addr.s_addr=inet_addr(argv[1]);
	 s.sin_port=htons(atoi(argv[2]));
	 rval=connect(sockid,(struct sockaddr*)&s,sizeof(s));
	 if(rval==-1)
 	 {
	   perror("CONN_ERR:");
	   close(sockid);
 	   exit(1);
 	 }
         printf("\nEnter the request message : ");
	 scanf("%s",m1);
	 rval=send(sockid,m1,sizeof(m1),0);
	 if(rval==-1)
	 {
	   perror("MSG_SEND_ERR:");
	   close(sockid);
 	   exit(1);
 	 }
 	 printf("\nMessage sent successfully");
	 rval=recv(sockid,m2,sizeof(m2),0);
	 if(rval==-1)
	 {
   	   perror("MSG_RCV_ERR:");
           close(sockid);
  	   exit(1);
 	 }
	 printf("\nServer response is : %s\n",m2);
	 close(sockid);
}
