#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void ENQUE();
void DELQUE();
void DISPLAY();

int main()
{
	int ch;
	char ans;
	
	do
	{
		printf("\n----------------------------");
		printf("\n MENU:\n Enter 1 to insert an element.\n Enter 2 to delete an element.\n Enter 3 to display.\n Enter 4 to exit.\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				ENQUE();
				break;
				
			case 2:
				DELQUE();
				break;
				
			case 3:
				DISPLAY();
				break;
				
			case 4:
				break;
				
			default:
				printf("Wrong Input. Try again.\n");
		}
		
		printf("Do you want to continue? Enter Y/y for yes.");
		scanf(" %c",&ans);		//notice space before %c
	}while(ans=='Y'||ans=='y');
}

void ENQUE()
{
	struct node *nN= (struct node*)malloc(sizeof(struct node));
	
	printf("Enter the data:");
	scanf("%d",&nN->data);
	nN->next=NULL;
	
	if(front==NULL && rear==NULL)
	{
		front=nN;
		rear=nN;
	}
	
	else
	{
		rear->next=nN;
		rear=rear->next;
	}
}

void DELQUE()
{
	struct node *temp;
	
	if(front==NULL)
		printf("UNDERFLOW.\n");
		
	else if(front==rear)
	{
		front=NULL;
		rear=NULL;
	}
	
	else
	{
		temp=front;
		front=front->next;
		printf("Deleted element is %d.\n",temp->data); 
		free(temp);
	}
}

void DISPLAY()
{
	struct node *temp;
	
	if(front==NULL)
		printf("UNDERFLOW.\n");
		
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			printf("%d \t",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
