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
node *head1= NULL;
node *head2= NULL;
node *head3= NULL;

node* insert(node *head, int data)						//INSERT AT END
{	
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
	return head;
}

node* merge(node* head1, node* head2, node* head3)				//head1 and head2 are local to this function
{
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data < head2->data)
		{
			head3= insert(head3, head1->data);
			head1= head1->next;
		}
		
		else
		{
			head3= insert(head3, head2->data);
			head2= head2->next;;
		}
	}
	
	if(head1==NULL)
	{
		while(head2!= NULL)
		{
			head3= insert(head3, head2->data);
			head2= head2->next;;
		}
	}
	
	if(head2==NULL)
	{
		while(head1!= NULL)
		{
			head3= insert(head3, head1->data);
			head1= head1->next;;
		}
	}
	
	return head3;
}

void print(node *head)
{
	node *temp= head;
	
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	char ch;
	int data;
	
	cout<<"Enter the elements of the first linked list((IN SORTED ORDER)):\n ";
	do
	{
		cout<<"Enter data: ";
		cin>>data;
		
		head1= insert(head1,data);
		
		cout<<"Do you want to add more elements? Enter y/Y for yes. ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	
	print(head1);
	
	cout<<"Enter the elements of the second linked list((IN SORTED ORDER)): \n ";
	do
	{
		cout<<"Enter data: ";
		cin>>data;
		
		head2= insert(head2,data);
		
		cout<<"Do you want to add more elements? Enter y/Y for yes. ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	
	print(head2);
	
	head3= merge(head1,head2,head3);
	
	cout<<"\nSORTED MERGED LIST:\n";
	print(head3);
}
