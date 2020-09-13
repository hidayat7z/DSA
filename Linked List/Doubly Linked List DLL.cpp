#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *start=NULL;


void ins_at_beg();
void del_from_beg();
void ins_at_end();
void del_from_end();
void ins_at_pos();
void del_from_pos();
void display();


int main()
{
	int ch;
	char ans;
	
	printf("%d",sizeof(struct node));
	
	do
	{
		printf("\n----------------------------");
		printf("\n MENU:\n Enter 1 to insert at the beginning.\n Enter 2 to delete from the beginning.\n Enter 3 to insert at the end.\n Enter 4 to delete from the end.\n Enter 5 to insert at any position.\n Enter 6 to delete from any position.\n Enter 7 to display.\n");
		scanf("%d",&ch);
		
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
				display();
				break;
				
			default:
				printf("Invalid Input. Try again.\n");
		}
		
		printf("Do you want to continue? Enter Y/y for yes.");
		scanf(" %c",&ans);		//notice space before %c
	}while(ans=='Y'||ans=='y');
}

void ins_at_beg()
{
	struct node *nN;
	nN=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter the value:");
	scanf("%d",&nN->data);
	
	if(start==NULL)
	{
		start=nN;
		nN->prev=NULL;
		nN->next=NULL;
	}
	
	else
	{
		nN->next=start;
		start->prev=nN;
		start=nN;
		start->prev=NULL;
	}
}

void del_from_beg()
{
	if(start==NULL)
	{
		printf("Empty List.\n");
	}
	
	else
	{
		printf("Deleted element is %d.\n",start->data);
		
		if(start->prev==NULL&&start->next==NULL)		//if only one node remain....(me)
		{
			start=NULL;
		}
		else
		{
			start=start->next;
			free(start->prev);
			start->prev=NULL;
		}
	}
}

void ins_at_end()
{
	struct node *nN,*temp;
	nN=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter the value:");
	scanf("%d",&nN->data);
	
	if(start==NULL)
	{
		start=nN;
		nN->prev=NULL;
		nN->next=NULL;
	}
	
	else
	{
		temp=start;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nN;
		nN->prev=temp;
		nN->next=NULL;
	}
}

void del_from_end()
{
	struct node *temp;
	
	if(start==NULL)
	{
		printf("EmptY lisT.\n");
	}
	else
	{
		if(start->prev==NULL&&start->next==NULL)
		{
			printf("Deleted element is %d.\n",start->data);
			start=NULL;
		}
		else
		{
			temp=start;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			printf("Deleted element is %d.\n",temp->data);
			(temp->prev)->next=NULL;
			temp->prev=NULL;
			free(temp);
		}
	}
}

void ins_at_pos()
{
	int pos,c=1;
	struct node *nN,*temp;
	nN=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter the value:");
	scanf("%d",&nN->data);
	
	printf("Enter the position:");
	scanf("%d",&pos);
	
	temp=start;
	
	while(c<(pos-1))			//jaha insert karna hai usse pehle rok rahe hai temp ko like in SLL
	{
		temp=temp->next;
		c++;
	}
	nN->prev=temp;
	nN->next=temp->next;
	(temp->next)->prev=nN;
	temp->next=nN;
	}
}

void del_from_pos()
{
	int pos,c=1;
	struct node *temp;
	
	printf("Enter the position:");
	scanf("%d",&pos);
	
	if(start==NULL)
	{
		printf("EMPTY LIST");
	}
	
	else
	{
		temp=start;
		while(c<pos)
		{
			temp=temp->next;
			c++;
		}
		printf("Deleted element is %d.\n",temp->data);
		(temp->prev)->next=temp->next;
		(temp->next)->prev=temp->prev;
		free(temp);
	}
}

void display()
{
	struct node *temp;
	
	if(start==NULL)
		printf("EMPTY LIST.\n");
		
	else
	{
		temp=start;
		while(temp!=NULL)
		{
			printf("%d \t",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
