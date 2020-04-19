#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
    struct node *next;
}NODE;
NODE*create_node(int k)     //Function to create a node
{
	NODE*temp=(NODE*)malloc(sizeof(NODE));
	temp->next=NULL;
	temp->info=k;
	return temp;
}
void insert(NODE **head,int i)  //Function to create list
{
	NODE *temp=create_node(i);
	if(*head==NULL)
	{
		*head=temp;
		return;
	}
	temp->next=*head;
	*head=temp;
}
NODE* rev_recur(NODE*head)   //This is the recursive reversing function
{
   if(head==NULL||head->next==NULL)
   return head;
   NODE* temp=rev_recur(head->next);
   head->next->next=head;
   head->next=NULL;
   return temp;
}
NODE* rev_iter(NODE *head)   //This is the Iterative reversing function
{
	NODE*prev,*current,*after;
	prev=NULL;
	current=head;
	while(current!=NULL)
	{
		after=current->next;
		current->next=prev;
		prev=current;
		current=after;
	}
	head=prev;
	return head;
	
}
		
void print_list(NODE*head)  //Function to print list
{
	NODE*temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("\t%d",temp->info);
		temp=temp->next;
	}
}
	
void main()
{
	NODE *head;
	head=NULL;
	insert(&head,5);
	insert(&head,9);
	insert(&head,101);
	printf("\nList before reversing : ");
	print_list(head);
	head=rev_recur(head);
	printf("\nList after reversing using recursion : ");
	print_list(head);
	printf("\nList after reversing again using iterative statements : ");
	head=rev_iter(head);
	print_list(head);
	getch();
}
