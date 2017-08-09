#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse2(char *start,char *end)
{
char temp;
while(start < end)
	{
	temp=*start;
	*start++=*end;
	*end--=temp;
	}
}

void reverseword(char str[])
{
char *word_start=str;
char *drag=str;
while(*drag)
	{
	drag++;
	if(*drag == '\0')
		{
		reverse2(word_start,drag-1);
		}
	else if (*drag == ' ')
		{
		reverse2(word_start,drag-1);
                word_start=drag+1;
		}

	}
printf("reverse2:%s\n",str);
reverse2(str,drag-1);
}

void reverse(char str[])
{
int len,i;
len=strlen(str);
printf("Len:%d\n",len);
for(i=0;i<len/2;i++)
	{
	str[i] = str[i] ^ str[len-i-1];
	str[len-i-1] = str[i] ^ str[len-i-1];
	str[i] = str[i] ^ str[len-i-1];
	}
        printf("str:%s\n",str);	

}

void copy(char str[],char dst[])
{
int i=0;
while(str[i])
	{
	dst[i]=str[i];
	i++;
	}
}

int compare(char src[],char src1[])
{
int i=0;
while(src[i] != '\0' && src1[i] != '\0')
{
	if(src[i] == src1[i])
	{
	i++;
	}
	else
	{
	return (src[i]-src1[i]);
	}
}
return (src[i]-src1[i]);
}
void concat(char str[],char dst[])
{
int i=0;
int len=strlen(dst);
while(str[i])
{
dst[len+i]=str[i];
i++;
}
printf("concat:%s\n",dst);
}
int main()
{
char src[]="Sundar is good";
char src1[]="sundar is good";
char dst[30];
int res;
copy(src,dst);
res=compare(src,src1);
if(!res)
	{
	printf("strings are equal\n");
	}
else
	{
	printf("Strings are not equal and error value is :%d\n",res);
	}

printf("dst:%s\n",dst);
concat(src,dst);
reverse(src);
reverseword(src);
printf("Reversed:%s\n",src);
return 0;
}
