/* Find first non repeating/unpaired element in an array */
/*Logic is multiply all the array elements with XOR the unique number/unpaired will be the final output */
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *arr,ele,res,i;
	arr=(int *)malloc(sizeof(int));
	printf("Enter the numbers of elements \n");
	scanf("%d",&ele);
	printf("Enter the array element \n");
	for(i =0; i<ele;i++)
		{
		scanf("%d",&arr[i]);
		}

	res=arr[0];

	for(i = 1;i<ele;i++)
		{
		res = res ^ arr[i];
		}

	printf("Non repeating element in the given array is :%d\n",res);
}
