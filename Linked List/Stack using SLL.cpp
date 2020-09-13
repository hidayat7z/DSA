#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *top=NULL;

void push();
void pop();
void display();

int main()
{
	int ch;
	char ans;
	
	do
	{
		printf("\n MENU:\n Enter 1 to insert an element.\n Enter 2 to delete an element.\n Enter 3 to display.\n Enter 4 to exit.\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				push();
				break;
				
			case 2:
				pop();
				break;
				
			case 3:
				display();
				break;
				
			case 4:
				break;
				
			default:
				printf("Wrong Input. Try again.\n");
		}
		
		printf("Do you want to continue? Enter Y/y for yes.");
		scanf(" %c",&ans);	
	}while(ans=='Y'||ans=='y');
}

void push()
{
	struct node *nN= (struct node*)malloc(sizeof(struct node));
	
	printf("Enter the data:");
	scanf("%d",&nN->data);
	nN->next=NULL;
	
	if(top==NULL)
		top=nN;
	
	else
	{
		nN->next=top;
		top=nN;
	}
}

void pop()
{
	struct node *temp;
	
	if(top==NULL)
		printf("UNDERFLOW");
		
	else
	{
		temp=top;
		top=top->next;
		printf("Deleted element is %d",temp->data);
		free(temp);
	}
}

void display()
{
	struct node *temp;
	
	if(top==NULL)
		printf("UNDERFLOW\n");
		
	else
	{
		temp=top;
		while(temp!=NULL)
		{
			printf("%d \n",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
