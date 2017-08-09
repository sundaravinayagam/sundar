/*String functions using pointers*/

#include<stdio.h>
#include<stdlib.h>


/*Function to get the length of the string */
void strlength(char *str)
{
	int len=1;
	while(*++str)
		len++;
	printf("String length:%d\n",len);

}

/*Function to compare two strings */
void strcomp(char *str1,char *str2)
{
	int comp=1;
	while (*str1 != '\0' && *str1 == *str2)
    	{
	++str1;
        ++str2;
    	}
	if(*str1 == *str2)
		comp=0;
	
	
	if(!comp)
		printf("Both strings are equal \n");
	else
		printf("Both strings are not equal \n");
	
}


/*Function to copy input string */
void strcopy(char *str3,char *str2)
{
	char *s=str3;
	while(*str2)
	{
	*s=*str2;
	*s++;
	*str2++;
	}
		
	*s='\0';
	printf("Copied string is :%s\n",str3);
}


/*Function to concatenate input string */
void strconcat(char *str1,char *str2)
{
	char *s=str1;
	while(*s != '\0')
		*s++;
	while(*str2 != '\0')
		*s++=*str2++;
	printf("Concatenated string is :%s\n",str1);
	
}


/*Function to reverse the string */
void strrever(char *str1,char *str3)
{
int len=0,i,j=0;
while(*(str1+len)!='\0')
{
len++;
}
for(i=len-1;i>=0;i--,j++)
	{
	*(str3+j)=*(str1+i);
	}
	printf("reverse string:%s\n",str3);
}




/*Main program*/
int main()
{
	char *str1;
	char *str2;
        char *str3;
	int  opt;
	
	printf("Enter the option: \
                  1.Copy	\
		  2.Compare	\
		  3.Concate	\
		  4.Reverse	\
		  5.Length	\n");
	scanf("%d",&opt);

        str1=(char *)malloc(sizeof(char));
	printf("Enter String 1\n");
	scanf("%s",str1);

	str2=(char *)malloc(sizeof(char));	
	printf("Enter String2\n");
	scanf("%s",str2);

	str3=(char *)malloc(sizeof(char));

	switch(opt)
		{
		case 1:strcopy(str3,str2);
			break;
		case 2:strcomp(str1,str2);
			break;
		case 3:strconcat(str1,str2);
			break;
		case 4:strrever(str1,str3);
			break;
		case 5:strlength(str1);
			break;
		default:printf("Wrong input selection \n");
			break;
		}
}
