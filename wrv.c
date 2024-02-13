#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/uio.h>
#include<fcntl.h>
#include<string.h>
main(int argc,char *argv[])
{
	int fd,rval,i;
	char *s1,*s2,*s3;
	s1=(char *)malloc(30);
	s2=(char *)malloc(30);
	s3=(char *)malloc(30);
	struct iovec iov[3];
	fd=open(argv[1],O_WRONLY | O_CREAT);
	if(fd!=-1)
	{
		printf("\nEnter three strings: ");
		printf("\nString 1:");
		scanf("%s",s1);
		printf("\nString 2:");
		scanf("%s",s2);
		printf("\nString 3:");
		scanf("%s",s3);
		iov[0].iov_base=s1;
		iov[0].iov_len=strlen(s1);
		iov[1].iov_base=s2;
		iov[1].iov_len=strlen(s2);
		iov[2].iov_base=s3;
		iov[2].iov_len=strlen(s3);
		for(i=0;i<3;i++)
		printf("\nValue of s[%d] is %s of length %d\n",i,iov[i].iov_base,iov[i].iov_len);
		rval=writev(fd,(struct iovec *)&iov,3);
		if(rval==-1)
		perror("Writev_err");
	}
	else
	perror("File open");
}
	
