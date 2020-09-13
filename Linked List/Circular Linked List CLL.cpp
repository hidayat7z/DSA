#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start= NULL;

void ins_at_beg();
void del_from_beg();
void ins_at_end();
void del_from_end();
void display();

int main()
{
	int ch;
	char ans;
	
	printf("%d",sizeof(struct node));
	
	do
	{
		printf("\n----------------------------");
		printf("\n MENU:\n Enter 1 to insert at the beginning.\n Enter 2 to delete from the beginning.\n Enter 3 to insert at the end.\n Enter 4 to delete from the end.\n Enter 5 to display.\n");
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
	struct node *nN,*temp;
	
	nN=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter data: ");
	scanf("%d",&nN->data);
	nN->next=NULL;
	
	if(start==NULL)
	{
		start=nN;
		nN->next=nN;
	}
	
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			temp=temp->next;	
		}
		temp->next=nN;
		
		nN->next=start;
		start=nN;
	}
}

void del_from_beg()
{
	struct node *temp,*temp2;
	
	if(start==NULL)
		printf("EMPTY LIST.\n");
		
	else if(start->next==start)		//if only one node element in the list
	{
		printf("Deleted element is %d.\n\n",start->data);
		start=NULL;
	}
	
	else
	{		
		temp=start;
		temp2=start;
		
		printf("Deleted element is %d.\n\n",temp->data);
		
		while(temp2->next!=start)
		{
			temp2=temp2->next;
		}
		start=start->next;
		temp2->next=start;
		
		free(temp);
	}
	
}

void ins_at_end()
{
	struct node *nN,*temp;
	
	nN=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter data: ");
	scanf("%d",&nN->data);
	nN->next=NULL;
	
	if(start==NULL)
	{
		start=nN;
		nN->next=nN;
	}
	
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		temp->next=nN;
		nN->next=start;
	}
}

void del_from_end()
{
	struct node *temp,*pretemp;
	
	if(start==NULL)
		printf("EMPTY LIST.\n");
	
	else if(start->next==start)		//if only one node element in the list
	{
		printf("Deleted element is %d.\n\n",start->data);
		start=NULL;
	}
	
	else
	{
		temp=start;
		pretemp=temp;
		while(temp->next!=start)
		{
			pretemp=temp;
			temp=temp->next;
		}
		printf("Deleted element is %d.\n\n",temp->data);
		pretemp->next=start;
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
		while(temp->next!=start)
		{
			printf("%d \t",temp->data);
			temp=temp->next;
		}
		printf("%d \t",temp->data);		//last node data print
		
		printf("\n");
	}
}
