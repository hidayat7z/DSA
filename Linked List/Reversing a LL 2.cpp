// METHOD 2:
// TIME COMPLEXITY : O(n)
// using ""returning two values from a function using objects""

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

class Pair
{
	public:
		node* head;
		node*tail;
};

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

Pair reverseLL(node *head)
{
	if(head==NULL || head->next==NULL)
	{
		Pair ans;								//creating an object of class pair
		ans.head= head;
		ans.tail= head;
		
		return ans;
	}
		
	Pair smallAns= reverseLL(head->next);		//smallAns is an object of class pair
	
	smallAns.tail->next= head;
	head->next= NULL;
	
	Pair ans;
	ans.head= smallAns.head;
	ans.tail= head;
	
	return ans;
}

node* reverse(node* head)
{
	Pair finalAns= reverseLL(head);
	
	return finalAns.head;
}
	
/* METHOD 1:

	node *temp= smallAns;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
	temp->next= head;
	head->next=NULL;
	
	return smallAns;
*/

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
	
	head= reverse(head);
	
	cout<<"\n Reversed Linked List:\n";
	print();
}
