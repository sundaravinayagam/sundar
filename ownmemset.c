#include<stdio.h>
#include<stdlib.h>
void mymemset(void *ptr,int val,int len)
{
if(ptr!=NULL && len > 0)
	{
	unsigned char *temp=ptr;
        int i=0;
	for(i=0;i<len;i++)
		{
		*temp++=(unsigned char)val;
		}
	}
	
}
int main()
{
char *ptr;
ptr=(char *)malloc(sizeof(char));
mymemset(ptr,'a',sizeof(ptr));
puts(ptr);
}
