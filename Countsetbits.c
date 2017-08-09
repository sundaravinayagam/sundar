/* Count number of set bits in an integer*/

#include<stdio.h>
#include<stdlib.h>

int countsetbit(int n)
{
	int count=0;
	while(n)
		{
		if ( n & 1)
                   count++;
		n = n >> 1;
		}
return count;	
}

int countsetbit2(int n)
{
	int count=0;
	while(n)
		{
		n = n & (n-1);
		count++;
		}
return count;
}

void main()
{
	int n,res;
	printf("Enter the number \n");
	scanf("%d",&n);
	res= countsetbit(n);
	printf("Number of set bits in %d is :%d\n",n,res);
	res= countsetbit2(n);
	printf("Number of set bits in %d is :%d\n",n,res);
}
