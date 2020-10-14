#include<iostream>
using namespace std;

template <typename T>

class stack
{
	T* data;
	int index;
	int capacity;
	
	public:
		
		stack()
		{
			data= new T[3];
			index=0;
			capacity=3;
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
		
		void push(T element)
		{
			if(index==capacity)
			{
				T *newData= new T[2*capacity];
				
				for(int i=0;i<capacity;i++)
				{
					newData[i]=data[i];
				}
				
				delete [] data;
				data= newData;
				
				capacity= 2*capacity;
			}
			
			data[index++]= element;
		}
		
		T pop()
		{
			if(index==0)
				return -1;
			
			else
				return data[--index];
		}
		
		T top()
		{
			if(index==0)
				return -1;
			
			else
				return data[index-1];
		}
};

stack <char> s1;

bool checkBalanced(char* exp)
{
	int i=0;
	while(exp[i] != '\0')
	{
		char x= exp[i];
		
		if(x=='(' || x=='[' || x=='{')
		{
			s1.push(x);
		}
		
		else if(x==')' || x==']' || x=='}')
		{
			if(x==')' && s1.top()=='(')
			{
				char k= s1.pop();
			}
			
			else if(x=='}' && s1.top()=='{')
			{
				char k= s1.pop();
			}
			
			else if(x==']' && s1.top()=='[')
			{
				char k= s1.pop();
			}
			else
			{
				return false;				// ex: (a+b)] or ((a+b)])
			}
		}
		
		else
		{
			int a=1;					//dont use continue as it will skip
										//all the statements below it
		}
		
		i++;
	}
	
	if(s1.isEmpty()==1)					//checking if stack is empty
		return true;
	else
		return false;

}

int main()
{
	char s[100];
	
	cout<<"Enter the expression: ";
	cin>>s;
	
	int k= checkBalanced(s);
	
	if(k==0)
		cout<<"\n NOT BALANCED";
	else
		cout<<"\n BALANCED.";
}
