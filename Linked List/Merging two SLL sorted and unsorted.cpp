#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start1= NULL;				//sorted list1
struct node *start2= NULL;				//sorted list2
struct node *start3= NULL;				//sorted merged list
struct node *start4= NULL;				//unsorted merged list

struct node *createList(struct node*,int);
void display(struct node*);
struct node *sortedM();
struct node *unsortedM();

int main()
{
	int n1,n2,i,ch,val;
	char ans;
	
	printf("Enter the no. of elements of you want in List 1: ");
	scanf("%d",&n1);
	printf("Enter the no. of elements of you want in List 2: ");
	scanf("%d",&n2);
	
	printf("Enter the elements of LIST 1-- ");
	i=0;
	while(i<n1)
	{
		scanf("%d",&val);
		start1=createList(start1,val);
		i++;
	}
	display(start1);
	printf("\n\n");
	
	printf("Enter the elements of LIST 2-- ");
	i=0;
	while(i<n2)
	{
		scanf("%d",&val);
		start2=createList(start2,val);
		i++;
	}
	display(start2);
	printf("\n\n");
	
	do
	{
		printf("\n MENU:\n Enter 1 for sorted merging.\n Enter 2 for unsorted merging.\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				start3 = sortedM();
				display(start3);
				break;
				
			case 2:
				start4 = unsortedM();
				display(start4);
				break;
				
			default:
				printf("Wrong Input. Try Again.\n");
		}
		
		printf("Do you want to continue? Enter y/Y for yes.");
		scanf(" %c",&ans);
	}while(ans=='y'||ans=='Y');
}

struct node *createList(struct node *start,int val)
{
	struct node *nN,*temp;

	nN=(struct node*)malloc(sizeof(struct node));

	nN->data=val;
	nN->next=NULL;

	if(start==NULL)
		start=nN;

	else
	{
		temp=start;

		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nN;
	}
	return start;
}

void display(struct node *start)
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

struct node *sortedM()
{
	struct node *temp1,*temp2;
	temp1=start1;
	temp2=start2;
	
	if(start1->data < start2->data)
	{
		start3=createList(start3,start1->data);
		temp1=temp1->next;
	}
	
	else
	{
		start3=createList(start3,start2->data);
		temp2=temp2->next;
	}
	
	while(temp1!=NULL && temp2!=NULL)			//// We are using && and not  ||. Think WHY
	{							
		if(temp1->data < temp2->data)
		{
			start3=createList(start3,temp1->data);
			temp1=temp1->next;
		}
			
		else
		{
			start3=createList(start3,temp2->data);
			temp2=temp2->next;
		}
		
	}
	
	if(temp2==NULL)
	{
		while(temp1!=NULL)
		{
			start3=createList(start3,temp1->data);
			temp1=temp1->next;	
		}
	}
	
	else
	{
		while(temp2!=NULL)
		{
		start3=createList(start3,temp2->data);
		temp2=temp2->next;	
		}
	}
		
	return start3;
}

struct node *unsortedM()
{
	/*
	   list1: 2, 4 ,6
	   list2: 3, 5, 7
	   list4: 2,4,6,3,5,7
	*/
	struct node *temp1,*temp2;
	
	temp1=start1;
	while(temp1!=NULL)
	{
		if(start4==NULL)
		{
			start4=createList(start4,start1->data);
			temp1=temp1->next;	
		}
		
		else
		{
			start4=createList(start4,temp1->data);
			temp1=temp1->next;
		}
	}
	
	temp2=start2;
	while(temp2!=NULL)
	{
		start4=createList(start4,temp2->data);
		temp2=temp2->next;
	}
	
	return start4;
}
