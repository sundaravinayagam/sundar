/* Number is power of 2 or not */
#include<stdio.h>
#include<stdlib.h>

int chkpowof2_1(int n)
{
 if(n < 2)
	return n;
 else
 	return (n & (n-1));
}

int chkpowof2_2(int n)
{
	int count=0;
	if( n >= 2)
	{
	while(n)
		{
		if( n & 1)
		   count++;
		n = n >> 1;
		}
	}
return count;		
}

void main(void)
{
	int n,res;
	printf("Enter the number \n");
	scanf("%d",&n);
	res=chkpowof2_1(n);
	if(!res)
		printf("Number %d is power of two \n",n);
	else
		printf("Number %d is not power of two \n",n);
	res=chkpowof2_2(n);
	if(res == 1)
		printf("Number %d is power of two \n",n);
	else
		printf("Number %d is not power of two \n",n);
}
