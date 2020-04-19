#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node*next;
};
typedef struct node NODE;
struct LinkedList
{
	NODE*head;
	NODE*tail;
};
typedef struct LinkedList LL;
LL list;
NODE*create_node(int k)
{
	NODE*temp=(NODE*)malloc(sizeof(NODE));
	if(temp==NULL)
	return NULL;
	temp->info=k;
	temp->next=NULL;
	return temp;
}
void insert_front(LL*list,int k)
{
	NODE*temp=create_node(k);
	if(temp==NULL)
	{
		printf("Malloc failed");
		return ;
	}
	if(list->head==NULL)
	{
		list->head=list->tail=temp;
    } 
	else
	{
		temp->next=list->head;
		list->head=temp;
	}
}
int remove_front(LL*list)
{
	int k;
	NODE*temp=list->head;
	if(list->head==NULL)
		return;
	else if(list->head==list->tail&&list->head!=NULL)
	{
		k=temp->info;
		list->head=list->tail=NULL;
		free(temp);
		return k;
	}
	else
	{
		k=temp->info;
		list->head=temp->next;
		free(temp);
		return k;
	}
}
void insert_end(LL*list,int k)
{
	NODE*temp=create_node(k);
	if(list->head==NULL)
		insert_front(list,k);
	else
	{
		list->tail->next=temp;
		list->tail=temp;
	}
}
int remove_end(LL*list)
{
	int k;
	NODE*temp=list->head;
	if(list->head==list->tail&&list->head!=NULL)
		remove_front(list);
	else
	{
		while(temp->next!=list->tail)
		temp=temp->next;
		k=list->tail->info;
		free(list->tail);
		temp->next=NULL;
		list->tail=temp;
		return k;
	}
}
void insert_nth(LL*list,int k,int n)
{
	int i;
	NODE*temp=list->head,*temp2;
	for(i=1;temp->next!=NULL;i++)
		temp=temp->next;
	if(n==1)
		insert_front(list,k);
	else if(n>i)
		insert_end(list,k);
	else
	{
		temp=list->head;
		for(;n-2>0;n--)
		temp=temp->next;
		temp2=create_node(k);
		temp2->next=temp->next;
		temp->next=temp2;
	}
}
int remove_nth(LL*list,int n)
{
	int i,k;
	NODE*temp=list->head;
	NODE*temp2;
	for(i=1;temp->next!=NULL;i++)
		temp=temp->next;
	if(n==1)
		remove_front(list);
	else if(n>i)
		remove_end(list);
	else
	{
		temp=list->head;
		for(;n-2>0;n--)
		temp=temp->next;
		temp2=temp->next;
		k=temp2->info;
		temp->next=temp2->next;
		free(temp2);
		return k;
	}
}
void print_list(LL*list)
{
	NODE*temp=list->head;
	if(temp==NULL)
	return;
	while(temp!=NULL)
	{
		printf("%i ",temp->info);
		temp=temp->next;
	}
}
int main()
{
	int option,n,k;
	list.head=NULL;
	list.tail=NULL;
	while(1)
	{
		printf("\n\nEnter the desired option :\n1.Enter Front \n2.Remove Front\n3.Enter nth position \n4.Remove nth position\n5.Enter end \n6.Remove Rear\n7.Print list\n");
		scanf("%i",&option);
		switch(option)
		{
			case 1:
				{
					printf("Enter the number : ");
					scanf("%i",&k);
					insert_front(&list,k);
					break;	
				}
			case 2:
				{
					printf("Number at the front is %i\n",remove_front(&list));
					break;
				}
			case 3:
				{
					printf("Enter the number : ");
					scanf("%i",&k);
					printf("Enter the position : ");
					scanf("%i",&n);
					insert_nth(&list,k,n);
					break;
				}
			case 4:
				{
					printf("Enter the position : ");
					scanf("%i",&n);	
					printf("Number at the %ith position is %i\n",n,remove_nth(&list,n));
					break;
				}
			case 5:
				{
					printf("Enter the number : ");
					scanf("%i",&k);
					insert_end(&list,k);
					break;	
				}
			case 6:
				{
					printf("Number at the end is %i\n",remove_end(&list));
					break;
				}
			case 7:
				{
					print_list(&list);
					break;
				}
			default:
				exit(1);
		}
	}
	return 0;
	getch();
}
