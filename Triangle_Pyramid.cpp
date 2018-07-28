#include "stdafx.h"
#include "iostream"
using namespace std;

void pattern(int );

void main()
{
	int n;
	cout<<"Enter value of n\n";
	cin>>n;
	pattern(n);
}

void pattern(int n)
{
	int count =0;
	for(int i =0;i<n;i++)
	{
		for(int j =0;j<=i;j++)
		{
			count++;
			if(j!=0)
			{
				cout<<"*"<<count;
			}

			else
			{
				cout<<count;
			}
		}
		cout<<"\n";
	}
}