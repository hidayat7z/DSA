#include<stdio.h>
#define MAX 5

int q[MAX],front=-1,rear=-1;

void CENQUE();
void CDELQUE();
void CDISPLAY();

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
				CENQUE();
				break;
				
			case 2:
				CDELQUE();
				break;
				
			case 3:
				CDISPLAY();
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

void CENQUE()
{
	int val;
	
	if((front==0 && rear==MAX-1)||(front==(rear+1)))
		printf("OVERFLOW");
	
	else
	{	
		printf("Enter element you wanna insert:");
		scanf("%d",&val);
		
		if(front==-1 && rear==-1)
		{
			front=0;
			rear=0;
		}
		
		else
			rear=(rear+1)%MAX;
			
		q[rear]=val;	
	}
}

void CDELQUE()
{
	int item;
	
	if(front==-1&&rear==-1)
		printf("UNDERFLOW");
		
	else
	{
		item=q[front];
		
		if(front==rear)			//single element present
		{
			front=-1;
			rear=-1;
		}
		
		else
			front=(front+1)%MAX;
	}
	
	printf("Item deleted is: %d.",item);
}

void CDISPLAY()
{
	int i;
	
	if(front==-1 && rear==-1) 
		printf("UNDERFLOW");
	
	else
	{	
		if(front<=rear)
		{
			printf("\n\n...QUEUE ITEMS:\n");
			for(i=front;i<=rear;i++)
				printf("%d \n",q[i]);
		}
		
		else
		{
			printf("\n\n...QUEUE ITEMS:\n");
			
			for(i=front;i<MAX;i++)
				printf("%d \n",q[i]);
			
			for(i=0;i<=rear;i++)
				printf("%d \n",q[i]);
		}
	}
}


