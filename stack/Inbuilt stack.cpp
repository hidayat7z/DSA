#include<iostream>
using namespace std;

#include<stack>

int main()
{
	stack <int> s1;
	
	s1.push(10);
	s1.push(20);
	s1.push(30);
	
	cout<<endl<<s1.size()<<endl;
	
	cout<<endl<<s1.top()<<endl;
	
	// cout<<endl<<s1.pop()<<endl;					DOESN'T WORK. pop() rertuns void
	
	s1.pop();
	cout<<endl<<s1.top()<<endl;
	
	cout<<endl<<s1.size()<<endl;
	
}
