/* Number of bits to be flipped to convert a to b *

ex: for 4 0100 and for 5 0101 so number of bits to be flipped is 1 */

#include<stdio.h>
#include<stdlib.h>
void main()
{
int a,b,flip,count;
printf("Enter first number:\n");
scanf("%d",&a);
printf("Enter second number:\n");
scanf("%d",&b);

flip= a ^ b; /* main part:  XOR will give diff or two numbers*/

while(flip)
	{
	if( flip & 1)
		count++;
	flip=flip >> 1;
	}
printf("Number of bits to be flipped between %d and %d is %d\n",a,b,count);
}
