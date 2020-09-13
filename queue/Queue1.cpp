#include<iostream>
using namespace std;

template <typename T>

class queue
{
	T* data;
	int capacity;
	int nextIndex;
	int firstIndex;						//index of first element
	int size;
	
	public:
		
		queue(int s)
		{
			data = new T[s];
			capacity= s;
			size= 0;
			nextIndex= 0;
			firstIndex= -1;
		}
		
		int getSize()
		{
			return size;
		}
		
		bool isEmpty()
		{
			return size == 0;
		}
		
		void enQ(T element)								//nextIndex is managed here.
		{
			if(size==capacity)
			{
				cout<<"\n QUEUE FULL.";
				return;
			}
			
			data[nextIndex]= element;
			
			nextIndex= (nextIndex + 1) % capacity;
			
			if(firstIndex== -1)
			{
				firstIndex= 0;
			}
			
			size++;
		}
		
		T front()
		{
			if(isEmpty())					//can use getSize() or size or firstIndex too
			{
				cout<<"\n EMPTY QUEUE";
				return 0;
			}
			
			return data[firstIndex];
		}
		
		T delQ()										//frontIndex is managed here.
		{
			if(isEmpty())
			{
				cout<<"\nEMPTY QUEUE.";
				return 0;
			}
			
			T ans= data[firstIndex];
			firstIndex = (firstIndex + 1) % capacity;
			size--;
			
			if(size==0)						//resetting if the queue gets empty
			{
				firstIndex= -1;
				nextIndex= 0;
			}
			
			return ans;
		}
};

int main()
{
	int n,y,ch;
	char ans;
	
	cout<<"Enter the size of the queue: ";
	cin>>n;
	
	queue <int> q1(n);
	
	do
	{
		cout<<"\n----------------------------";
		cout<<"\n MENU:\n Enter 1 to insert .\n Enter 2 to delete .\n Enter 3 to display the front element.\n Enter 4 to display the current size of the queue.\n";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"Enter element: ";
				cin>>n;
				q1.enQ(n);
				break;
			
			case 2:
				y= q1.delQ();
				cout<<endl<<y<<endl;
				break;
				
			case 3:
				y= q1.front();
				cout<<endl<<y<<endl;
				break;
				
			case 4:
				y= q1.getSize();
				cout<<endl<<y<<endl;
				break;
				
			default:
				cout<<"Invalid Input. Try again.\n";
		}
		
		cout<<"Do you want to continue? Enter Y/y for yes.";
		cin>>ans;
	}while(ans=='Y'||ans=='y');
}
