//Client Program UDP echo service
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h>
main(int argc,char *argv[])
{
 	 struct sockaddr_in s,c;
	 int rval,sockid,slen;
	 char m1[20],m2[20];
	 system("clear");
	 if(argc<3)
       	 {
  	   printf("\n USAGE : %s IP_ADDRESS PORT#\n",argv[0]);
 	   exit(1);
 	 }
	 sockid=socket(AF_INET,SOCK_DGRAM,0);
	 if(sockid==-1)
 	 {
           perror("SOCK_CRE_ERR:");
           exit(1);
	 }
	 s.sin_family=AF_INET;
	 s.sin_addr.s_addr=inet_addr(argv[1]);
	 s.sin_port=htons(atoi(argv[2]));
	 printf("\n Enter the request message : ");
	 scanf("%s",m1);
	 slen=sizeof(s);
	 rval=sendto(sockid,m1,sizeof(m1),0,(struct sockaddr*)&s,slen);
	 if(rval==-1)
 	 {
	   perror("MSG_SEND_ERR:");
 	   exit(1);
 	 }
 	 printf("\nMessage sent successfully");
	 strncpy(m2," ",20);
	 rval=recvfrom(sockid,m2,sizeof(m2),0,(struct sockaddr*)&s,&slen);
	 if(rval==-1)
	 {
   	   perror("MSG_RCV_ERR:");
  	   exit(1);
 	 }
	 printf("\nMessage received is : %s\n",m2);
	 close(sockid);
}
