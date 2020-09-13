// LINKED LIST

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

void ins_at_beg()
{
	int data;
	
	cout<<"Enter data: ";
	cin>>data;
		
	node* nN= new node(data);
	
	if(head==NULL)
		head= nN;
	
	else
	{
		nN->next= head;
		head= nN;
	}
}

void ins_at_pos()
{
	int pos, data, count=1;
	
	cout<<"Enter position:";
	cin>>pos;
	
	cout<<"Enter data:";
	cin>>data;
	
	node *nN= new node(data);
	
	if(pos==1)
	{
		nN->next=head;
		head=nN;
	}
	else
	{
		node *temp= head;
		
		while(count<(pos-1) && temp!=NULL)
		{
			temp=temp->next;
			count++;
		}
		
		nN->next= temp->next;
		temp->next=nN;
	}
}

void ins_at_end()
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

void del_from_beg()
{
	if(head==NULL)
		cout<<"EMPTY LIST";
		
	else
	{
		node* temp= head;
		head=head->next;
		delete temp;
	}
}

void del_from_pos()
{
	int pos, count=1;
	
	cout<<"Enter position:";
	cin>>pos;
	
	if(head==NULL)
		cout<<"EMPTY LIST";
	
	else if(pos==1)
	{
		node* temp= head;
		head=head->next;
		delete temp;	
	}
		
	else
	{
		node* temp= head;
		node *pretemp= temp;
		
		while(count<pos && temp!= NULL)
		{
			pretemp=temp;
			temp= temp->next;
			count++;
		}
		pretemp->next= temp->next;
		delete temp;
	}
		
}

void del_from_end()
{
	if(head==NULL)
		cout<<"EMPTY LIST";
		
	else
	{
		node *temp= head;
		
		while( (temp->next)->next != NULL)
		{
			temp=temp->next;
		}
		
		delete temp->next;
		temp->next= NULL;
	}
}

void lenLL()
{
	int count=0;
	node *temp= head;
	
	if(head==NULL)
	{
		cout<<"EMPTY LIST";
	}
	
	else
	{
		while(temp!=NULL)
		{
			temp=temp->next;
			count++;
		}
		
		cout<<"Length= "<<count;
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

int main()
{
	int ch;
	char ans;
	
	
	do
	{
		cout<<"\n----------------------------";
		cout<<"\n MENU:\n Enter 1 to insert at the beginning.\n Enter 2 to delete from the beginning.\n Enter 3 to insert at the end.\n Enter 4 to delete from the end.\n Enter 5 to insert at any position.\n Enter 6 to delete from any position.\n Enter 7 to display.\n Enter 8 to find length of the list.\n";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				ins_at_beg();
				break;
				
			case 2:
				del_from_beg();
				break;
		
			case 3:
				ins_at_end();
				break;
			
			case 4:
				del_from_end();
				break;
		
			case 5:
				ins_at_pos();
				break;
			
			case 6:
				del_from_pos();
				break;
				
			case 7:
				print();
				break;
				
			case 8:
				lenLL();
				break;
				
			default:
				cout<<"Invalid Input. Try again.\n";
		}
		
		cout<<"Do you want to continue? Enter Y/y for yes.";
		cin>>ans;
	}while(ans=='Y'||ans=='y');
}
