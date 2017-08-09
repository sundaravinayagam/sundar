#include<stdio.h>
#include<stdlib.h>
#define swapnibble(x) (((x & 0x0F0F) << 4)|((x & 0xF0F0) >> 4))
void main()
{
	int n=0x1234;
	int newn,val,newval;
	newn=swapnibble(n);
	printf("%x\n",newn);
	
}
