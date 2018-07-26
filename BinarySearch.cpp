// BinarySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

void sort(int *arr,int);
void display(int *arr,int);
int bSearch(int *arr,int,int,int);

int main()
{
	int *arr,size,i,f,val;
	char ch = 'y';
	cout<<"Enter the size of the array\n";
	cin>>size;
	arr = new int[size];
	cout<<"Enter the elements of the array\n";
	for(i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	sort(arr,size);
	display(arr,size);
	while(ch == 'y' || ch == 'Y')
	{
		cout<<"\nEnter the element to be searched\n";
		cin>>val;
		f=bSearch(arr,val,0,size-1);
		if(f==1)
		{
			cout<<"found\n";
		}
		else
		{
			cout<<"Not found\n";
		}
		cout<<"Do You wish to continue further :(Y/N)\n";
		cin>>ch;
	}

	delete [] arr;
	return 0;
}

void sort(int *arr,int size)
{
	int i,j,key;
	for(j=1;j<size;j++)
	{
	    key = arr[j];
		i = j-1;
		while(i>=0 && arr[i] > key)
		{
			arr[i+1] = arr[i];
			i=i-1;
		}
		arr[i+1] = key;
	}
}

void display(int *arr,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<*arr<<" ";
		arr++;
	}
}

int bSearch(int *arr,int val,int L,int U)
{
	
	int f=0,mid;
	if(L<=U)
	{
	
			mid = (L+U)/2;

		if(arr[mid] == val)
		{
			f=1;
		}

		else if(arr[mid] > val)
		{
			return bSearch(arr,val,L,mid-1);
		}
		else if(arr[mid] < val)
		{
			return bSearch(arr,val,mid+1,U);
		}
		else
		{ 
			return f;
		}
	}
	return f;
}

