#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/uio.h>
#include<fcntl.h>
#include<string.h>
main(int argc,char *argv[])
{
	int fd,rval,i;
	char s1[7],s2[2],s3[10];
	bzero(s1,sizeof(s1));
	bzero(s2,sizeof(s2));
	bzero(s3,sizeof(s3));
	struct iovec iov[3];
	iov[0].iov_base=s1;
        iov[0].iov_len=sizeof(s1);
        iov[1].iov_base=s2;
        iov[1].iov_len=sizeof(s2);
        iov[2].iov_base=s3;
        iov[2].iov_len=sizeof(s3);	
	fd=open(argv[1],O_RDONLY);
	if(fd!=-1)
	{
		rval=readv(fd,(struct iovec *)&iov,3);
		if(rval!=-1)
		for(i=0;i<3;i++)
		printf("\nValue of s[%d] is %s of length %d\n",i,iov[i].iov_base,iov[i].iov_len);
		else
		perror("readv_err");
	}
	else
	perror("File open");
}
	
