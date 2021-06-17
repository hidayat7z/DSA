/*
Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n][n];
	
	for(int i=0; i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	}
	
	cout<<endl;
	for(int i=0; i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
			
		cout<<endl;
	}
	cout<<endl;
											//transposing the matrix
	for(int i=0; i<n;i++)
	{
		for(int j=i;j<n;j++)				//j=i and not 0 so that we dont swap 2 elements twice and end up with the same matrix lol
		{
			int temp= arr[i][j];
			arr[i][j]= arr[j][i];
			arr[j][i]= temp;
		}
	}
	
	for(int i=0; i<n/2;i++)
	{
		for(int j=0;j<n;j++)
		{										
			int temp= arr[i][j];					
			arr[i][j]= arr[n-1-i][j];				
			arr[n-1-i][j]= temp;
		}
	}
	
	for(int i=0; i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
			
		cout<<endl;
	}
}
