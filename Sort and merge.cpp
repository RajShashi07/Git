// Sort and merge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

void sort(int*,int*,int,int);
void merge(int*,int*,int,int);

int _tmain(int argc, _TCHAR* argv[])
{
	int  *arr1, *arr2;
	int size1, size2;
	cout<<"Size of first array\n";
	cin>>size1;	
	arr1 = new int[size1];
	cout<<"Enter the elements\n";
	for(int i =0;i<size1;i++)
	{
		cin>>arr1[i];
	}

	cout<<"Size of second array\n";
	cin>>size2;
	arr2 = new int[size2];
	cout<<"Enter the elements\n";
	for(int i=0;i<size2;i++)
	{
		cin>>arr2[i];
	}

	sort(arr1,arr2,size1,size2); // SOrting both the arrays..
	merge(arr1,arr2,size1,size2); // Merge both arrays in sorted form.
	return 0;
}

void sort(int* arr1, int* arr2, int size1, int size2)
{
	int val1;
	int val2;
	for(int i =0;i<size1;i++)
	{
		val1 = arr1[i];
		int j =i;
		while( arr1[j-1] > val1  && j>=0)
		{
			arr1[j] = arr1[j-1];
			j--;
		}

		arr1[j] = val1;
	}

	for(int i =0;i<size2;i++)
	{
		int val2 = arr2[i];
		int j =i;
		while( arr2[j-1] > val2 && j>=0)
		{
			arr2[j] = arr2[j-1];
			j--;
		}

		arr2[j] = val2;
	}

	// Display sorted arrays.
	for(int i=0;i<size1;i++)
	{
		cout<<arr1[i];
	}
	cout<<"\n";
	for(int i=0;i<size2;i++)
	{
		cout<<arr2[i];
	}
	cout<<"\n";
}

void merge( int* arr1,int* arr2, int size1, int size2)
{
	int size;
	int *arr;
	int k =0, i=0, j=0;
	size = size1+ size2;
	arr = new int[size];
	
	while(i<size1 && j<size2)
	{
		if(arr1[i] >= arr2[j])
		{
			arr[k] = arr2[j];
			k++;
			j++;
		}
		
		else if(arr1[i] <= arr2[j])
		{
			arr[k] = arr1[i];
			k++;
			i++;
		}
	}

	while(i < size1)
	{
		arr[k] = arr1[i];
		i++;
		k++;
	}

	while(j < size2)
	{
		arr[k] = arr2[j];
		j++;
		k++;
	}

	for(k=0;k<size;k++)
	{
		cout<<arr[k];
	}

}