#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int sum=arr[0], maxx=arr[0];
	for(int i=1; i<n; i++)
	{
		sum= max(arr[i], sum+arr[i]);	
		maxx= max(maxx,sum);
	}
	cout<<maxx;
}
