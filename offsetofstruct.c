/*This program will help us to find the offset of a structure element */
#include<stdio.h>
#include<stdlib.h>
#include <stddef.h>
struct test
{
int i;
int j;
int k;
};
int main()
{
printf("%p\n", &((struct test *)NULL)->j);
printf("offsetof:%p\n",(long)offsetof(struct test,k));
}
