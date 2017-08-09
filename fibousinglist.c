#include<stdio.h>
#include<stdlib.h>

typedef struct ls
{
int data;
struct ls *next;
}LIST;

LIST *fibo(LIST *head,int n)
{
LIST *newnode=(LIST *)malloc(sizeof(LIST)), *temp=head;
newnode->data=n;
newnode->next=NULL;


while(temp->next!=NULL)
temp=temp->next;

temp->next=newnode;

return head;
}

void display(LIST *head)
{
while(head!=NULL)
{
printf("%d",head->data);
if(head->next != NULL)
printf(" --> ");

head=head->next;
}

printf("\n");
}

int main()
{
LIST *head=(LIST *)malloc(sizeof(LIST));
int a,b,c,i,terms;

head->data=0;
head->next=NULL;

printf("The no. of terms to be built for fibonacci series : ");
scanf("%d",&terms);

a = 0; b = 1; c = 0;

for(i=1; i<=terms; i++)
{
a = b;
b = c;
c = a + b;
head=fibo(head,c);
}

display(head);

return 0;
}
