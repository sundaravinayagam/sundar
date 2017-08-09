#include<stdio.h>
#include<stdlib.h>
struct list
{
int n;
struct list *link;
};

void printlist(struct list *p)
{
	struct list *temp = p;
	while(temp != NULL)
	{
		printf("%d\n",temp->n);
		temp=temp->link;
	}
}
struct list *reverse(struct list *start)
{
	struct list *prev = NULL;
	struct list *curr = start;
	struct list *next;

	while(curr != NULL)
	{
		next = curr->link;
		curr->link=prev;
		prev=curr;
		curr=next;	
	}
	
	start = prev;

	return(start);
}

void push(struct list **head, int item)
{

struct list *p;
p = (struct list *)malloc(sizeof(struct list));

p->n=item;
p->link=*head;
*head=p;

}

int main()
{
struct list *first = NULL;
struct list *p;
push(&first,4);
push(&first,5);
push(&first,6);
push(&first,7);
push(&first,8);
push(&first,9);
push(&first,6);

printlist(first);

p=reverse(first);
printlist(p);
return 0;
}
