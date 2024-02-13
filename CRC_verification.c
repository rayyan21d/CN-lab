#include<stdio.h>
#include<string.h>
main()
{
	int i,j,k,m,n,cl;
	char a[10],c[100];
	system("clear");
	printf("Enter polynomial: ");
	scanf("%s",a);
	printf("Ente the CRC frame : ");
	scanf("%s",c);
	m=strlen(a);
	cl=strlen(c);
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
	n=cl-m+1;
	for(i=0;i<n;i++)
	{
		if(c[i]=='1')
		{
			for(j=i,k=0;k<m;k++,j++)
				if(a[k]==c[j])
					c[j]='0';
				else
					c[j]='1';
		}	
	}
	for(i=0;i<cl;i++)
	if(c[i]=='1')
	{
		printf("There is some error in message: ");
		break;
	}
	if(i==cl)
		printf("\nMessage is correct");
}
