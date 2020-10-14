#include<iostream>
#include<queue>

using namespace std;

int main()
{
	priority_queue<int> pq;
	
	pq.push(16);
	pq.push(1);
	pq.push(167);
	pq.push(7);
	pq.push(45);
	pq.push(32);
	
	cout<<"SIZE: "<<pq.size()<<endl;
	cout<<"TOP: "<<pq.top()<<endl;
	
	while( !pq.empty() )
	{
		cout<<pq.top()<<"\t";
		pq.pop();
	}
}
