#include<iostream>
using namespace std;

#include<queue>

int main()
{
	queue <int> q1;
	
	q1.push(10);
	q1.push(20);
	q1.push(30);
	
	cout<<endl<<q1.size()<<endl;
	
	cout<<endl<<q1.front()<<endl;
	
	// cout<<endl<<s1.pop()<<endl;					DOESN'T WORK. pop() rertuns void
	
	q1.pop();
	cout<<endl<<q1.front()<<endl;
	
	cout<<endl<<q1.size()<<endl;
	
	cout<<endl<<q1.empty()<<endl;
	
	q1.push(40);
	q1.push(50);
	
	while( !q1.empty() )
	{
		cout<<endl<<q1.front();
		q1.pop();
	}
}
