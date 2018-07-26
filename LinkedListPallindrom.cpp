// Pallindrome_linkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

const int SIZE = 20;

class node
{
	int data;
	node* link;
	int top;
	int ArrayofStack[SIZE];
public:
	node(int);
	void push(int);
	int pop();
	void insert(node**,int);
	bool check_pallindrome(node **);
	void display(node **);
};

node ::node(int _top):top(_top)
{}
	
void node ::insert(node** start,int val)
{
	if((*start)==NULL)
	{
		(*start)=(node*)malloc(sizeof(node));
		(*start)->data=val;
		(*start)->link=NULL;
	}

	else
	{
		struct node *temp=(*start);
		while( temp->link!=NULL)
		{
			temp=temp->link;
		}
		struct node* temp1=(node*)malloc(sizeof(node));
		temp->link=temp1;
		temp1->data=val;
		temp1->link=NULL;
	}
}


void node :: push(int data)
{
	if(top == SIZE)
	{
		cout<<"Stack is full\n";
	}

	else
	{
		top = top+1;
		ArrayofStack[top]=data;
	}
}

int node ::pop()
{
	int element;
	if(top == -1)
	{
		cout<<"stack is empty\n";
	}

	else
	{
		element = ArrayofStack[top];
		top--;
	}
	return element;
}

bool node :: check_pallindrome(node **start)
{
	node *temp1,*temp2;
	int element;
	temp1=(*start);
	temp2=(*start);

	if(temp1->link == NULL)
	{
		return true;
	}
	while(temp1 != NULL && temp1->link != NULL)
	{
		temp1=temp1->link->link;
		push(temp2->data);
		temp2=temp2->link;
	}

    if(temp1 != NULL)
	{
	  temp2=temp2->link;
	while(temp2 != NULL)
	{
		if(temp2->data == ArrayofStack[top])
		{
			element = pop();
			temp2=temp2->link;
		}
		

		else if(temp2->data != ArrayofStack[top])
		{
			return false;
			break;
		}
	}

	return true;
	}


	else if(temp1 == NULL)
	{
	while(temp2 != NULL)
	{
		if(temp2->data == ArrayofStack[top])
		{
			element = pop();
			temp2=temp2->link;
		}
		

		else if(temp2->data != ArrayofStack[top])
		{
			return false;
			break;
		}
	}

	return true;
	}
}

void node :: display(node** start)
{
	node *temp = (*start);
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->link;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct node* head=NULL;
	node n(-1);
	int ch,a;
	cout<<"\n1:Insert  2:CheckPallindrome 3:Display"<<endl;		
	while(1)
	{
		cout<<"\nEnter your choice\n";
		cin>>ch;
		switch(ch)
		{
		case 1: 
			cout<<"Enter the value to be inserted\n";
			cin>>a;
			n.insert(&head,a);
			break;
		case 2:
			if(n.check_pallindrome(&head))
				{
					cout<<"Pallindrom\n";
			    }
			else
				{
					cout<<"Not Pallindrom\n";
			    }    
			break;
		case 3:
			n.display(&head);
			break;
		default:
			cout<<"Wrong entry \n";
			exit(0);
			break;
		}
	}
	return 0;
}
