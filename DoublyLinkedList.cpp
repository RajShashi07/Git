// DoublyLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

struct node
{
	node* next;
	node* prev;
	int data;
};

void insertNodeEnd(struct node**, int);
void insertNodeBeg(struct node**, int);
void displayList(struct node**);

int _tmain(int argc, _TCHAR* argv[])
{
	struct node* head= NULL;
	int data, choice;
	while(1)
	{
		cout<<"\n1: InsertNodeBeg 2:InsertNodeEnd 3:DisplayList\n";
		cout<<"Enter your choice\n";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"Enter data\n";
			cin>>data;
			insertNodeBeg(&head,data);
			break;
		case 2:
			cout<<"Enter data\n";
			cin>>data;
			insertNodeEnd(&head,data);
			break;
		case 3:
			displayList(&head);
			break;
		default :
			cout<<"Wrong entry";
			exit(0);
		}
	}
	
return 0;
}

void insertNodeBeg(struct node** start,int data)
{
	struct node* NewNode = (node*) malloc (sizeof(node));
	NewNode->data = data;
	NewNode->next = NULL;
	NewNode->prev = NULL;

	if((*start) == NULL)
	{
		(*start) = NewNode;
	}

	else
	{
		NewNode->next = (*start);
		(*start) = NewNode;
	}
}
void insertNodeEnd(struct node **start, int data)
{
	struct node* NewNode = (node*) malloc (sizeof(node));
	NewNode->data = data;
	NewNode->next = NULL;
	NewNode->prev = NULL;

	if((*start) == NULL)
	{
		(*start) = NewNode;
	}
		
	
	else
	{
		struct node* tempNode = (*start);
		while(tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}

		tempNode->next = NewNode;
		NewNode->prev = tempNode;
	}
}
	

void displayList(struct node** start)
{
	if((*start) == NULL)
	{
		cout<<"Empty list\n";
	}

	struct node* tempNode = (*start);
	while(tempNode != NULL)
	{
		cout<<tempNode->data;
		tempNode = tempNode->next;
	}
}









