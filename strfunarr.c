/*String functions using arrays*/

#include<stdio.h>
#include<stdlib.h>


/*Function to identify the String Length */
void strlength(char str[])
{
	int i=0;
	while(str[i])
		{
		i++;
		}
	printf("Length of the String is:%d\n",i);
}


/*Function to concatenate the String*/
void strconcat(char str1[],char str2[])
{
	int len=0,i=0;
	while(str1[len])
		{
		len++;
		}
	while(str2[i])
		{
		str1[len+i]=str2[i];
		i++;
		}
	printf("Concatenated string is :%s\n",str1);
}


/*Function to copy the String*/
void strcopy(char str3[],char str2[])
{
	int i=0;
	while(str2[i])
		{
		str3[i]=str2[i];
		i++;
		}
	printf("Copied string is:%s\n",str3);
}

/*Function to Compare the Strings*/
void strcomp(char str1[],char str2[])
{
	int i=0,check=1;
	while(str1[i] != '\0' || str2[i] != '\0')
		{
		if(str1[i] == str2[i])
		  {
			check=0;
			i++;
			continue;
			
		  }
		else
		  break;
		}
        if(!check)
		printf("Both Strings are Equal \n");	
	else
		printf("Both Strings are not equal \n");
	

}


/*Function to reverse the string*/
void strrever(char str[])
{
	int len=0,i;
	while(str[len])
		{
		len++;
		}
	for(i=0;i<len/2;i++)
	{
	str[i] = str[i] ^ str[len-i-1];
	str[len-i-1] = str[i] ^ str[len-i-1];
	str[i] = str[i] ^ str[len-i-1];
	}
        printf("str:%s\n",str);	

}



/*Main program*/
int main()
{
	char str1[30];
	char str2[10];
        char str3[10];
	int  opt;
	
	printf("Enter the option: \
                  1.Copy	\
		  2.Compare	\
		  3.Concate	\
		  4.Reverse	\
		  5.Length	\n");
	scanf("%d",&opt);
	
	printf("Enter String 1\n");
	scanf("%s",str1);

	printf("Enter String2\n");
	scanf("%s",str2);

	switch(opt)
		{
		case 1:strcopy(str3,str2);
			break;
		case 2:strcomp(str1,str2);
			break;
		case 3:strconcat(str1,str2);
			break;
		case 4:strrever(str1);
			break;
		case 5:strlength(str1);
			break;
		default:printf("Wrong input selection \n");
			break;
		}
}

	

	

	

	
