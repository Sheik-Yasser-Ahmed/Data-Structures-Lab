#include<stdio.h>
#include<stdlib.h>
struct btree{
	int info;
	struct btree *lchild,*rchild;
};
btree*	 create_node(int k){
	btree* temp=(btree*)malloc(sizeof(btree));
	temp->info=k;
	temp->lchild=NULL;
	temp->rchild=NULL;
		return temp;
}
void insert(int k,btree **root)
{
	btree*temp=create_node(k);
	if(*root==NULL)
	{
		*root=temp;
	}
	else if(k<(*root)->info)
	{
	
	     	if((*root)->lchild!=NULL)
	     	insert(k,&(*root)->lchild);
		    else
		    (*root)->lchild=temp;
    }
	else
	{
		if((*root)->rchild!=NULL)
		{
			insert(k,&(*root)->rchild);
		}
		else
		(*root)->rchild=temp;
		
		}	
	
}
void print_inorder(btree*root)
{
	if(root==NULL)
	return;
    print_inorder(root->lchild);
    printf("\t%d",root->info);
	print_inorder(root->rchild);
}
void print_preorder(btree*root)
{
	if(root==NULL)
	return;
	printf("\t%d",root->info);
	print_preorder(root->lchild);
	print_preorder(root->rchild);
}
void print_postorder(btree*root)
{
	if(root==NULL)
	{
	return;
}
	print_postorder(root->lchild);
	print_postorder(root->rchild);
	printf("\t%d",root->info);
}
main()
{
	int i,k;
	btree*root;
	root=NULL;
	while(1)
	{
		printf("\n1, Insert\n2.Print inorder\n3.Print preoder\n4.Print postorder\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1 : 	printf("Value of k :");
			scanf("%d",&k);
			insert(k,&root);
			break;
			case 2 : print_inorder(root);
			break;
			case 3 : print_preorder(root);
			break;
			case 4 : print_postorder(root);
			break;
			case 5 : exit(0);
			default :printf("\nError occured ");
			break;
		}
		
	}
}
