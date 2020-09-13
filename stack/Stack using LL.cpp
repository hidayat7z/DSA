#include<iostream>
using namespace std;

template <typename T>					//must be mentioned for each class
										//wherever me write Node for initialsing
										//it must be followed by <T>
class Node
{
	public:
		T data;
		Node <T> *next;
	
		Node(T data)
		{
			this->data= data;
			next= NULL;
		}
};

template <typename T>					//must be mentioned for each class
class Stack
{
	Node <T> *head;
	int size;
	
	public:
		
		Stack()
		{
			head= NULL;
			size=0;
		}
		
		int getSize()
		{
			return size;
		}
		
		bool isEmpty()
		{
			if(size==0)
				return true;
			else
				return false;
		}
		
		void push(T data)
		{
			Node <T> *nN= new Node<T>(data);
			size++;
			
			nN->next= head;
			head= nN;
		}
		
		T pop()
		{
			if(isEmpty())
			{
				cout<<"\nEMPTY STACK\n";
				return -1;
			}
			
			T ans= head->data;
			
			Node <T> *temp= head;

			head=head->next;
			
			delete temp;
			size--;
			return ans;
		}
		
		T top()
		{
			if(isEmpty())
			{
				cout<<"\nEMPTY STACK\n";
				return -1;
			}
			
			return head->data;
		}
};

int main()
{
	int ch,x,y;
	char ans;
	
	Stack <int> s1;
	
	do
	{
		cout<<"\n----------------------------";
		cout<<"\n MENUUU:\n Enter 1 to insert .\n Enter 2 to delete the topmost element.\n Enter 3 to display the topmost element.\n Enter 4 to display the current size of the stack.\n";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"Enter element: ";
				cin>>x;
				s1.push(x);
				break;
			
			case 2:
				y= s1.pop();
				cout<<endl<<y<<endl;
				break;
				
			case 3:
				y= s1.top();
				cout<<endl<<y<<endl;
				break;
				
			case 4:
				y= s1.getSize();
				cout<<endl<<y<<endl;
				break;
				
			default:
				cout<<"Invalid Input. Try again.\n";
		}
		
		cout<<"Do you want to continue? Enter Y/y for yes.";
		cin>>ans;
	}while(ans=='Y'||ans=='y');
}
