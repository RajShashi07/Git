// CreateTree1_Inorder _ Preorder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

const int SIZE = 10;
int count = 0;

struct node
{
	int data;
	node* llink;
	node* rlink;
};

struct node* insert(node*,int);
struct node* BuildTree(int inoder[SIZE],int preorder[SIZE],node*);
void display(node*);


int _tmain(int argc, _TCHAR* argv[])
{
	node *root = NULL;
	int inorder[SIZE] = {20,30,40,50,60,70,80};
	int preorder[SIZE] = {50,30,20,40,70,60,80};
	root = BuildTree(inorder, preorder , root);
	cout<<"The tree is"<<" ";
	display(root);
	cout<<"\n";

	return 0;
}

struct node* insert(struct node* root,int data)
{
	if(root == NULL)
	{
		struct node *temp = (struct node*) malloc(sizeof(node));
		temp->data = data;
		temp->llink = NULL;
		temp->rlink = NULL;
		root = temp;
	}

	else if(data < root->data)
	{
		root->llink =  insert(root->llink,data);
	}

	else if (data > root->data)
	{ 
		root->rlink = insert(root->rlink,data);
	}

	return root;
}

struct node* BuildTree(int inorder[SIZE], int preorder[SIZE] ,node* root)
{
	int i=0;
	while(preorder[i] != '\0')
	{
		int data = preorder[i];
		root = insert(root,data);
		i=i+1;
	}

	return root;
}


void display(node* root)
{
	if(root == NULL)
	{
		return ;
	}

	display(root->llink);
	display(root->rlink);
	cout<<" "<<root->data;
}


