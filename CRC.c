#include<stdio.h>
#include<string.h>
main()
{
	int i,j,k,m,n,cl;
	char a[10],b[100],c[100];
	system("clear");
	printf("\nEnter polynomial : ");
	scanf("%s",a);
	printf("\nEnter the frame : ");	
	scanf("%s",b);
	m=strlen(a);
	n=strlen(b);
	for(i=0;i<m;i++)
	{	
		if(a[i]=='1')
		{
			m=m-i;
			break;
		}
	}
	for(k=0;k<m;k++)
		a[k]=a[k+i];
	cl=m+n-1;
	for(i=0;i<n;i++)
		c[i]=b[i];
	for(i=n;i<cl;i++)
		c[i]='0';
	c[i]='\0';
	for(i=0;i<n;i++)
	if(c[i]=='1')
	{
		for(j=i,k=0;k<m;k++,j++)
		if(a[k]==c[j])
			c[j]='0';
		else
			c[j]='1';
	}
	for(i=0;i<n;i++)
		c[i]=b[i];
	printf("\nThe message is %s",c);
}

