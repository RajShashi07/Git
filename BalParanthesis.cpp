// BalParanthesis.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"

using namespace std;

const int size = 20;
class stack
{
private:
	int top;
	char *str;
	int size;
public:

	stack(int );
	void push(char , char*,int);
	void pop(char *);
	int check_bal(char *,int);
	bool comp(char,char);
};

int _tmain(int argc, _TCHAR* argv[])
{
	stack s(-1);
	char *str;
	str = new char[size];
	cout<<"Enter the expression\n";
	cin>>str;
	int f =s.check_bal(str,size);
	if(f==1)
		cout<<"Balanced\n";
	else
		cout<<"Not balanced\n";
	
	return 0;
}


stack :: stack(int _top):top(_top)
{
}

bool stack :: comp(char open , char close)
{
	switch(open)
	{
	case '[': 
		if(close == ']')
		{
		  return true;
		}
		break;

	case '{':
		if(close == '}')
		{
		  return true;
		}
		break;

	case '(':
		if(close == ')')
		{
		  return true;
		}
		break;

	default:
		return false;
		break;
	}

	return false;
}


int stack :: check_bal(char *exp,int size)
{
    int n;
	n = strlen(exp);
	for(int i= 0;i<n;i++)
	{
		if(exp[i]=='[' ||  exp[i]=='{' || exp[i]=='(')
		{
			push(exp[i],exp,size);
		}

		if(exp[i] == ']' || exp[i] == '}' || exp[i] == ')')
		{
			if(top==-1 || !comp(exp[top],exp[i]))
			{
				return false;
			}
			else
				pop(exp);
		}
	}

	if(top == -1)
	{
		return 1;
	}
	else 
	{
		return 0 ;
	}
		
}

void stack :: push(char ch,char *str,int size)
{
	if(top == size)
	{
		cout<<"Stack is full \n";
	}

	else
	{
		top++;
		str[top] = ch;
	}
}

void stack :: pop(char *str)
{
	char c;
	if(top == -1)
	{
		cout<<"Stack is empty\n";
	}

	else
	{
	    c=str[top];
		top--;
	}
}

		

