/* Number is odd or even : if 0th bit is set then odd else even */

#include<stdio.h>
#include<stdlib.h>

int oddoreven(int n)
{
	if( n & 1)
		return 1;
	else
		return 0;
}

void main()
{
	int n,res;
	printf("Enter the number :");
	scanf("%d",&n);
	res=oddoreven(n);
	if(res)
		printf("The number %d is odd\n",n);
	else
		printf("The number %d is even\n",n);
}
