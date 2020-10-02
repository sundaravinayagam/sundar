#include<stdio.h>

int fib(int n)
{
if(n <= 1)
  return n;
return (fib(n-1)+fib(n-2));
}

void fibonacci(int x,int y,int z,int n)
{
int i;
for(i=1;i<n;i++)
{
z=x+y;
x=y;
y=z;
printf("%d\n",z);
}
  
}

int factorial(int n)
{
if(n == 1)
  return 1;
return (n*factorial(n-1));
}

int main()
{
int n=9,first=0,second=1,third,fact;
printf("the %d th fib number is :%d\n",n,fib(n));
printf("%d\n%d\n",first,second);
fibonacci(first,second,third,n);
fact=factorial(n);
printf("factorial;%d\n",fact);
}
