// DYNAMIC ARRAYS

#include<iostream>
using namespace std;

class stackA
{
	int* data;
	int index;
	int capacity;
	
	public:
		
		stackA()
		{
			data= new int[3];
			index=0;									// is 0 and not -1 like we used to previously
			capacity= 3;
		}
		
		int size()
		{
			return index;
		}
		
		bool isEmpty()
		{
			if(index==0)
				return true;
			else
				return false;
		}
		
		void push(int element)
		{
			if(index==capacity)
			{
				int* newData= new int[2*capacity];
				
				for(int i=0;i<capacity;i++)
				{
					newData[i]= data[i];
				}
				
				delete [] data;
				data= newData;
				capacity= 2*capacity;
			}
			
			data[index++]= element;
		}
		
		int pop()
		{
			if(index==0)
			{
				cout<<"\n EMPTY STACK.\n";
				return -1;
			}
			
			return
				data[--index];
		}
		
		int top()
		{
			if(index==0)
			{
				cout<<"\n EMPTY STACK.\n";
				return -1;
			}
			
			return
				data[index - 1];
		}
};

int main()
{
	int ch,x,y;
	char ans;
	
	stackA s1;
	
	do
	{
		cout<<"\n----------------------------";
		cout<<"\n MENU:\n Enter 1 to insert .\n Enter 2 to delete the topmost element.\n Enter 3 to display the topmost element.\n Enter 4 to display the current size of the stack.\n";
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
				y= s1.size();
				cout<<endl<<y<<endl;
				break;
				
			default:
				cout<<"Invalid Input. Try again.\n";
		}
		
		cout<<"Do you want to continue? Enter Y/y for yes.";
		cin>>ans;
	}while(ans=='Y'||ans=='y');
}
