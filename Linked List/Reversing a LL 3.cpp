// METHOD 3:
// TIME COMPLEXITY : O(n)
// without using ""returning two values from a function using objects""
// clever way to find tail during recursion

#include<iostream>
using namespace std;

class node
{
	public:
		
		int data;
		node *next;
		
		node(int data)
		{
			this->data= data;
			next= NULL;
		}
};
node *head= NULL;

void insert()								//INSERT AT END
{
	int data;
	
	cout<<"Enter data:";
	cin>>data;
		
	node* nN= new node(data);				//using constructor to input value in node
		
	if(head==NULL)
	{
		head= nN;
	}
	else
	{
		node *temp= head;	
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		
		temp->next= nN;
	}
}

node* reverseLL(node *head)
{
	if(head==NULL || head->next==NULL)
		return head;
		
	node *smallAns= reverseLL(head->next);
	
	node *tail= head->next;
	
	tail->next= head;
	head->next=NULL;
	
	return smallAns;
}

void print()
{
	node *temp= head;
	
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
}

int main()
{
	char ch;
	
	cout<<"Enter the elements of the list.\n";
	do
	{
		insert();
		
		cout<<"Do you want to continue? Enter Y/y for yes.";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	print();
	
	head= reverseLL(head);
	
	cout<<"\n Reversed Linked List:\n";
	print();
}
