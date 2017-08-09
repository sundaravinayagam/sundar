#include<stdio.h>
#include<stdlib.h>
struct list 
{
int n;
struct list *next;
};

void push(struct list **head,int num)
{
	struct list *temp=(struct list*)malloc(sizeof(struct list));
	temp->n=num;
	temp->next=*head;
	*head=temp;
}

void printmiddle(struct list *head)
{
	struct list *slow=head;
	struct list *fast=head;
	while(fast && fast->next!=NULL)
		{
		slow=slow->next;
		fast=fast->next->next;
		}
	printf("middle:%d\n",slow->n);
}

void nthnode(struct list *head,int n)
{
	struct list *traverse=head;
	int count=0,i;
	while(traverse != NULL)
		{
		traverse=traverse->next;
		count++;
		}
	traverse=head;
	for(i=1;i<count-n+1;i++)
		{
		traverse=traverse->next;
		}
	printf("%d th from last node:%d\n",n,traverse->n);

}

void deletenode(struct list *head,struct list *n)
{
	struct list *temp=head;
	while(temp && temp->next!=NULL && temp->next!=n)
		{
       		temp=temp->next;	
		}
	temp->next=temp->next->next;
	free(n);
}

void print(struct list *head)
{	
	while(head!=NULL)
		{
		printf("head->data:%d\n",head->n);
		head=head->next;
		}
}
void main()
{
	struct list *head=NULL;
	push(&head,10);
	push(&head,20);
	push(&head,45);
        push(&head,25);
        push(&head,5);
        print(head);
	printmiddle(head); 
        nthnode(head,5);  
        deletenode(head,head->next->next); 
	print(head);   	
}
