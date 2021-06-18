/*
Find mirror inverse of an array
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n],newarr[n];
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	for(int i=0;i<n;i++)        //MAIN LOGIC
	{
		newarr[arr[i]]=i;
	}
	
	for(int i=0;i<n;i++)
		cout<<newarr[i]<<" ";	
}
