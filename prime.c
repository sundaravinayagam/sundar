/*Check the number is prime or not

The logic is if it is a prime number it should not be divisable by all of its previous numbers */

#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,i,count=0;
	printf("Enter the number\n");
	scanf("%d",&n);

        for(i=2;i<=n/2;i++)
	{
		if( n % i == 0)
		{	count++;
			break;
		}
	}
	if (count == 0 && n!=1)
		printf("%d is prime number\n",n);
	else
		printf("%d is not a prime number\n",n);
}
