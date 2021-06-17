/*
Take as input a 2-d array. Print the 2-D array in spiral form anticlockwise.
*/

#include<iostream>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;
	int arr[m][n];
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	}
	
	int i,a=0,c=0;					//a=row1  and    c=column1
	
	while(a<m && c<n)
	{
		for(i=a; i<m; i++)				
			cout<<arr[i][a]<<" ";	
		c++;												
										
		for(i=c; i<n; i++)					
			cout<<arr[m-1][i]<<" ";			
		m--;							
		
		if(c<n)							
		{
			for(i=m-1; i>=a; i--)		
				cout<<arr[i][n-1]<<" ";			
			n--;						
		}
		if(a<m)							
		{
			for(i=n-1; i>=c; i--)
				cout<<arr[a][i]<<" ";		
			a++;
		}	
	}	
}
