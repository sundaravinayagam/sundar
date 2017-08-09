/* atoi implementation :playing with ascii values of characters

example ascii value of 1 is 49 and 0 is  48 so result is 1 */

#include<stdio.h>
#include<stdlib.h>

int ownatoi(char *arr)
{
	int res=0;

	while(*arr)
	{
		res= res*10 + *arr-48; /* or *arr-'\0' */
		*arr++;
	}
return res;	
}

void main()
{
	char *arr="1992";
	int res;
	res=ownatoi(arr);
	printf("%d\n",res);
}
