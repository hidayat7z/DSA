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

void insert()			//INSERT AT END
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

void print()
{
	node *temp= head;
	
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
}

void midElement()
{
	if(head==NULL || head->next==NULL)
		cout<<"NO MID ELEMENT\n";
	
	else
	{
		node *slow= head;
		node *fast= head->next;
		
		while(fast!=NULL && fast->next!=NULL)
		{
			slow= slow->next;
			
			fast= (fast->next)->next;
		}
		
		cout<<"\n Mid element is: "<<slow->data<<endl;
	}
}

int main()
{
	int ch,k;
	char ans;
	
	int data,pos;
	
	do
	{
		cout<<"\n----------------------------";
		cout<<"\n MENU:\n Enter 1 to insert at the end.\n Enter 2 to display.\n Enter 3 to find mid element of the list.\n";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				insert();
				break;
			
			case 2:
				print();
				break;
				
			case 3:
				midElement();
				break;
				
			default:
				cout<<"Invalid Input. Try again.\n";
		}
		
		cout<<"Do you want to continue? Enter Y/y for yes.";
		cin>>ans;
	}while(ans=='Y'||ans=='y');
}
	
