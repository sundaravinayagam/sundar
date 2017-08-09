/*Check the number is palindrome or not 

to reverse the number first take reminder and next quotient inbetween store the revised number
*/

#include<stdio.h>
#include<stdlib.h>

void main()
{
int n,revn=0,reminder,orig;
printf("Enter the number:\n");
scanf("%d",&n);
orig=n;

while( n != 0)
	{
	reminder=n%10;
	revn=revn*10+reminder;
	n=n/10;
	}

if(orig == revn)
	printf("palindrome \n");
else
	printf("Not a palindrome \n");	
	
}
