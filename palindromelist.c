#include<stdio.h>
#include<stdlib.h>
struct list
{
char c;
struct list *next;
};


void push(struct list **head,char c)
{
	struct list *new;
	new=(struct list*)malloc(sizeof(struct list));
	new->c=c;
	new->next=*head;
	*head=new;
}


void print(struct list *head)
{
	while(head)
		{
		printf("head->c:%c\n",head->c);
		head=head->next;
		}
}

void reverse(struct list **head,struct list **newhead)
{
	
	struct list *temp;
	struct list *trav=*head;
	
	while(trav!=NULL)
		{
		temp=(struct list*)malloc(sizeof(struct list));
		temp->c=trav->c;
		temp->next=*newhead;
		*newhead=temp;
		trav=trav->next;
		}
}

void palindrome(struct list *head,struct list *newhead)
{
	while (head != NULL && newhead!= NULL)
		{
		if(head->c == newhead->c)
			{  printf("palindrome \n");
			return; }
		head=head->next;
		newhead=newhead->next;
		}
	printf("not palindrome \n");
}

void main()
{
	struct list *head=NULL;
	struct list *newhead=NULL;
	push(&head,'a');
	push(&head,'m');
	push(&head,'m');
	push(&head,'a');
	print(head);
	reverse(&head,&newhead);
	print(newhead);
	palindrome(head,newhead);
}
