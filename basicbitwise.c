/* check set clear and toggle */
#include<stdio.h>
#include<stdlib.h>

int setbit(int n,int pos)
{
	n = n | ( 1 << pos);
return n;	
}

int clearbit(int n,int pos)
{
	n = n & (~( 1 << pos));
return n;
}


int checkbit(int n,int pos)
{
	int res;
	res = n & (1 << pos);
return res;
}

int togglebit(int n,int pos)
{
	n = n ^ ( 1 << pos);
return n;
}


void main()
{
	int n,set,clr,tog,res,check;
	printf("Enter the number:\n");
	scanf("%d",&n);
	printf("Position to set:\n");
	scanf("%d",&set);
	printf("Position to clear:\n");
	scanf("%d",&clr);
	printf("Position to toggle:\n");
	scanf("%d",&tog);
	printf("Position to check:\n");
	scanf("%d",&check);
	res=setbit(n,set);
	printf("Result after set is :%d \n",res);
	res=clearbit(n,clr);
	printf("Result after clear is :%d \n",res);
	res=togglebit(n,tog);
	printf("Result after toggle is :%d \n",res);
	res=checkbit(n,check);
	if(res)
		printf("The %d th bit in %d is  set\n",check,n);
	else
		printf("The %d th bit in %d is  not set\n",check,n);
}
