// MidOfLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

class node
{
	int data;
	node *link;
public:
	void insert_beg(node **,int);
	void insert_end(node **,int);
	void delete_beg(node **);
	void delete_end(node **);
	void delete_pos(node **,int);
	void display(node**);
	int mid(node **);
};

int _tmain(int argc, _TCHAR* argv[])
{
	struct node *head = NULL;
	node n;
	int ch,a,value;
	cout<<"\n1:insertion_beg \n2: insertion_end \n3:delete_beg \n4:delete_end \n5:delete_pos \n6:display \n7:Mid";
	while(1)
	{
	cout<<"\nEnter the choice\n";
	cin>>ch;
	switch(ch)
	{
	case 1:
		cout<<"Enter the item to be inserted\n";
		cin>>a;
	     n.insert_beg( &head , a);
		break;
	case 2:
	    cout<<"Enter the item to be inserted\n";
		cin>>a;
	    n. insert_end( &head , a);
		break;
	case 3:
		n.delete_beg(&head);
        break;
	case 4:
		n.delete_end(&head);
        break;
	case 5:
		cout<<"Enter the item to be deleted\n";
		cin>>a;
		n.delete_pos(&head,a);
        break;
	case 6:
		n.display(&head);
		break;
	case 7:
	    value = n.mid(&head);
		cout<<"The mid value is"<<" "<<value;
		break;
	default:
		cout<<"Wrong entry\n";
		exit(0);
		break;
	}
	}
	return 0;
}

void node :: insert_beg(node ** start,int data)
{
	if((*start) == NULL)
	{
	    (*start) = (node*) malloc(sizeof(node));
		(*start)->data = data;
		(*start)->link = NULL;
	}

	else
	{
		struct node* temp = (node*) malloc(sizeof(node));
		temp->data = data;
		temp->link = (*start);
		(*start) = temp;
	}
}

void node::insert_end(node** start , int data)
{
	if((*start) == NULL)
	{
		(*start) = (node*) malloc (sizeof(node));
		(*start)->data = data;
		(*start)->link = NULL;
	}

	else
	{
		struct node *temp = (*start);
		while(temp->link != NULL)
		{
			temp=temp->link;
		}

		struct node* temp1 = (node*) malloc(sizeof(node));
		temp->link = temp1;
		temp1->data = data;
		temp1->link = NULL;
	}
}

void node::delete_beg(node **start)
{
	struct node* temp = (*start);
	if( temp->link == NULL)
	{
		free(temp);
	}

	else if(temp ->link != NULL)
	{
		(*start) = temp->link;
		free(temp);
	}
}

void node :: delete_end(node ** start)
{
	struct node* temp =(*start);
	if(temp->link==NULL)
	{
		free(temp);
	}
	else
	{
		while(temp->link->link!= NULL)
		{
			temp=temp->link;
		}
			free(temp->link);
			temp->link=NULL;
	}
}

void node :: delete_pos(node ** start, int val)
{
	struct node* temp=(*start);
	  while(temp->link->data != val)
	    {
		    temp=temp->link;
	    }
	   temp->link=temp->link->link;
		
}

void node :: display(node** start)
{
	struct node* temp=(*start);
	if(temp==NULL)
	{
		cout<<"List is empty\n";
	}

	else if(temp->link==NULL)
	{
		cout<<temp->data;
	}

	else 
	{
		cout<<"The data of the linked list\n";
	 while(temp!=NULL)
	  {
		cout<<temp->data;
		temp=temp->link;
	  }
	}
}

int node ::mid(node **start)
{
	struct node *temp , *temp1;

	temp = (*start);
	temp1 = (*start);

	while(temp->link != NULL && temp->link->link != NULL)
	{
		temp= temp->link->link;
		temp1=temp1->link;
	}

	return temp1->data;
}




