// RemoveDuplicateFromList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

class node
{
	int data;
	node* link;
public:
	void insert(node**,int);
	void remove_duplicate(node** );
	void display(node*);
};


void node :: insert(node** start,int val)
{
	if((*start) == NULL)
	{
		(*start) = (node*) malloc (sizeof(node));
		(*start)->data=val;
		(*start)->link=NULL;
	}

	else
	{
		node* temp = (*start);
		while(temp->link != NULL)
		{
			temp = temp->link;
		}

		node* temp1 = (node*) malloc (sizeof(node));
		temp->link=temp1;
		temp1->data=val;
		temp1->link=NULL;
	}
}

void node :: remove_duplicate(node** start)
{
	node *temp1,*temp2,*dup;
	temp1=(*start);

	while(temp1->link != NULL && temp1 != NULL)
	{
		temp2 = temp1;
		
		while(temp2->link != NULL && temp2 != NULL)
		{
			if(temp1->data != temp2->link->data)
			{
				temp2 = temp2->link;
			}

			else
			{
				dup=temp2->link;
				temp2->link=temp2->link->link;
				free(dup);
			}
		}

		temp1 = temp1->link;
	}
}

void node :: display(node* head)
{
	while(head != NULL)
	{
		cout<<head->data;
		head=head->link;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct node* head = NULL;
	node n;
    int data,choice;
	cout<<"\n1:Insert 2:Remove_duplicate 3:Display 4:Exit\n";
	while(1)
	{
	    cout<<"\nEnter the choice\n";
		cin>>choice;
		switch(choice)
	    {
		case 1:
			cout<<"Enter the item to be inserted\n";
			cin>>data;
			n.insert(&head,data); 
			break;
		case 2:
		    n.remove_duplicate(&head);
			break;
		case 3:
			n.display(head);
			break;
		default:
			exit(0);
			break;
		}
    }
		return 0;
}

