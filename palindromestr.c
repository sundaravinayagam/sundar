/* Check the string is palindrome or not */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void palindrome(char *str)
{
	int i=0,len,flag=0;;
	len=strlen(str);
        
        while(str[i])
	{
		printf("%c,%c \n",str[i],str[len-i-1]);
		if((str[i] != str[len-i-1]))
		{
			flag=1;
		}
		i++;
	}
		    	
        if( flag == 1)
		printf("string is not palindrome \n");
	else
		printf("string is a palindrome \n");

}

void main()
{
	char *str;
	str=(char *)malloc(sizeof(255));
	printf("Enter the string \n");
	scanf("%s",str);
	printf("Entered string is :%s\n",str);
	palindrome(str);
}
