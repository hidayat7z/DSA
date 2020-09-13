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

int lenRecursively(node* temp)
{
	if(temp==NULL)
		return 0;
	
	else
		return 1+ lenRecursively(temp->next);
}

node* insertRec(int data, int pos, node* temp)
{
	node *nN= new node(data);
	
	if(pos==0 && head==NULL)			// when linked list is empty
	{
		head= nN;
		return head;
	}
	
	if(pos==0)							//when we have to add a node at position 1
	{
		nN->next=head;
		head= nN;
		
		return head;	
	}
	
	if(pos==1)							//BASE CONDITION
	{
		nN->next=temp->next;
		temp->next=nN;
		
		return head;
	}
	
	else
		return insertRec(data, pos-1, temp->next);			//RECURSIVE CALL
}

node* deleteRec( int pos, node* temp) 
{
	if(head==NULL)								// No element in list
	{
		cout<<"EMPTY LIST";
		return head;
	}
	
	if(pos==0 && head->next==NULL)				// One element in list
	{
		delete head;
		head=NULL;
	}
	
	if(pos==0)									// Deleting the first element of a list with more than 1 element
	{
		node *t= head;
		head= head->next;
		
		delete t;
		return head;
	}
	
	if(pos==1)									//BASE CONDITION
	{
		node *t= temp->next;
		
		temp->next= (temp->next)->next;
		
		delete t;
		return head;
	}
	
	else
		return deleteRec(pos-1,temp->next);
	
}

void search()
{
	int data,c=1,flag=0;
	node *temp=head;
	
	cout<<"Enter element to be searched:";
	cin>>data;
	
	while(temp!= NULL)
	{
		if(temp->data== data)
		{
			cout<<"\nPosition: "<<c;
			flag=1;
			break;
		}
		
		temp=temp->next;
		c++;
	}
	
	if(flag==0)
		cout<<"\nElement not found.";
}

void AppendLastNToFirst()
{
	int n;
	
	cout<<"Enter n:";
	cin>>n;
	
	node *temp = head;
	node *t = head;           
	int i = -n;  
	                           
	while(temp->next!=NULL)
	{
		if(i>=0)
		{                          
			t = t->next;
		}
		temp = temp ->next;
		i++;
	}
	
	temp->next = head;                      
	head = t->next;                         
	t->next = NULL;                         

}

void printReverse(node *temp)
{
	if(temp==NULL)
		return;
	
	else
	{
		printReverse(temp->next);
	}
	
	cout<<temp->data<<"\t";
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
	int ch,k;
	char ans;
	
	int data,pos;
	
	do
	{
		cout<<"\n----------------------------";
		cout<<"\n MENU:\n Enter 1 to insert at the end.\n Enter 2 to display.\n Enter 3 to find length of the list.\n Enter 4 to find length of the list recursively.\n Enter 5 to insert at any position recursively.\n Enter 6 to delete from any position recursively.\n Enter 7 to find the position of an element.\n Enter 8 to append last n elements to the first of the list.\n Enter 9 to print linked list in reverse.";
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
				lenLL();
				break;
			
			case 4:
				k= lenRecursively(head);
				cout<<"Length= "<<k<<endl;
				break;
				
			case 5:
				cout<<"Enter data:";
				cin>>data;
				
				cout<<"Enter position:";
				cin>> pos;
				
				head= insertRec(data,pos-1,head);
				
				break;
				
			case 6:
				cout<<"Enter position:";
				cin>> pos;
				
				head= deleteRec(pos-1,head);
				
				break;
				
			case 7:
				search();
				break;
				
			case 8:
				AppendLastNToFirst();
				break;
				
			case 9:
				printReverse(head);
				break;
				
			default:
				cout<<"Invalid Input. Try again.\n";
		}
		
		cout<<"Do you want to continue? Enter Y/y for yes.";
		cin>>ans;
	}while(ans=='Y'||ans=='y');
}
	
