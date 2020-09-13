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

node* midElement(node *head)
{
	if(head==NULL)
		return head;
		
	node* slow= head;
	node* fast= head;
	
	while( fast->next!= NULL && (fast->next)->next!= NULL)
	{
		slow= slow->next;
		fast= (fast->next)->next;
	}
	
	return slow;
}

node *merge(node *head1, node* head2)
{
	if(head1==NULL)
		return head2;
		
	if(head2==NULL)
		return head1;
		
	node* head= NULL;
	node* tail= NULL;
	
	if(head1->data < head2->data)				//choosing the head&tail nodes of the merged list
	{
		head= head1;
		tail= head1;
		head1= head1->next;
	}
	else
	{
		head= head2;
		tail= head2;
		head2= head2->next;
	}
	
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data < head2->data)
		{
			tail->next= head1;				//adding node at the end of the merged list
			
			tail= tail->next;				//making tail the last node
			head1= head1->next;
		}
		
		else
		{
			tail->next= head2;
			
			tail= tail->next;
			head2= head2->next;;
		}
	}
	
	if(head1==NULL)								//we connect the tail to the head of the remaining list..WOW WOW
	{											//so no need for a loop						
		tail->next= head2;
	}
	if(head2==NULL)
	{
		tail->next= head1;
	}
	
	return head;
}

node *mergeSort(node *head)
{
	if(head==NULL || head->next == NULL)
		return head;
	
	node *mid= midElement(head);
	
	node *half1= head;
	node *half2= mid->next;
	
	mid->next=NULL;										//think why
	
	half1= mergeSort(half1);
	half2= mergeSort(half2);
	
	node *finalHead= merge(half1, half2);
	
	return finalHead;
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
	
	head=mergeSort(head);
	
	cout<<"\n Sorted Linked List:\n";
	print();
}
