// StackUsingLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

struct node
{
	int data;
	node* link;
};

struct node* Push(node*,int);
struct node* Pop(node*);
void display(node*);
node* reverse(node*);


struct node* Push(node* head, int data)
{   
	struct node* newNode = (node *)malloc(sizeof(node));
	
	newNode->data = data;
	newNode->link = NULL;

	if(head == NULL)
	{
		(head) = newNode;
	}

	else
	{
		struct node* tempHead = head;
		while(tempHead->link != NULL)
		{
			tempHead = tempHead->link;
		}
		
		tempHead->link = newNode;
	}

	return head;
}

struct node* reverse(node *head)
{
	node *currentNode, *prevNode = NULL, *nextNode;

	currentNode = head;
	while(currentNode != NULL)
	{
		nextNode = currentNode->link;
		currentNode->link = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}

	head = prevNode;
	return head;
}
		

node* Pop(node* head)
{
	int value;
	node *currentNode, *prevNode = NULL;

	if(head == NULL)
	{
		cout<<"Stack is empty\n";
		return head;
	}

	head = reverse(head);

	currentNode = head;

	prevNode = currentNode;
	currentNode = currentNode->link;
	value = prevNode->data;
	free(prevNode);
	head = currentNode;
	head = reverse(head);
	cout<<"The popped value is "<<value;
	return head;
}

void display(node *start)
{
	struct node* temp = start;
	if(temp== NULL)
	{
		cout<<"Stack is empty\n";
		return ;
	}

	else if(temp->link == NULL)
	{
		cout<<temp->data;
	}
    
	else
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->link;
		}
	}
}


int main( )
{
	int data,choice, val;
	struct node *head = NULL;
	
	while(1)
	{
		cout<<"\n 1:Push \n 2:Pop \n 3:Display \n";
		cin>>choice;

		switch(choice)
		{
		case 1:
			cout<<"Enter the data\n";
			cin>>data;
			head = Push(head,data);
			break;

		case 2:
			head  = Pop(head);
			break;

		case 3:
			display(head);
			break;

		default:
			cout<<"Wrong entry\n";
			exit(0);
		}
	}

	
	return 0;
}
