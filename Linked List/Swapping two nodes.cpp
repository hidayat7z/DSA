//swapping nodes with their links not just data.. LOOK UP g4g: ""Swap nodes in a LL without swapping data""

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start1= NULL;

struct node *createList(struct node*,int);
void display(struct node*);
struct node *swap(int,int);

int main()
{
	int n,i,ch,val,x1,x2;
	char ans;
	
	printf("Enter the no. of elements of you want in the list: ");
	scanf("%d",&n);
	
	printf("Enter the elements of the list-- ");
	i=0;
	while(i<n)
	{
		scanf("%d",&val);
		start1=createList(start1,val);
		i++;
	}
	display(start1);
	
	printf("Enter the two positions you want to swap:");
	scanf("%d %d",&x1,&x2);
	
	start1=swap(x1,x2);
	printf("\n\n List after swapping:\n");
	display(start1);
}

struct node* createList(struct node *start,int val)
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

struct node* swap(int x1,int x2)
{
	int c1,c2,t,q;
	struct node *temp1,*prevt1,*temp2,*prevt2,*temp3;
	
	x1=x1-1;
	x2=x2-1;
	c1=0;
	c2=0;
		
	if(x1>x2)						//good technique  (me)
	{
		q=x1;
		x1=x2;
		x2=q;
	}
	
	temp1=start1;
	while(x1!=c1)
	{
		prevt1=temp1;
		temp1=temp1->next;
		c1++;
	}
	temp2=start1;
	while(x2!=c2)
	{
		prevt2=temp2;
		temp2=temp2->next;
		c2++;
	}
	
	if(temp1==start1)									//if head node and some other node
	{
		if(temp1->next==temp2)								//adjacent nodes
		{
			temp1->next=temp2->next;
			temp2->next=temp1;
			start1=temp2;
		}
		
		else
		{
			start1=start1->next;
			temp1->next=temp2->next;
			prevt2->next=temp1;
			temp2->next=start1;
			start1=temp2;
		}
	}
	
	else if(temp1!= start1 && temp2->next==NULL)			//if last node and some other node
	{
		
		if(temp1->next==temp2)									//adjacent nodes
		{
			prevt1->next=temp1->next;
			temp2->next=temp1;
			temp1->next=NULL;
		}
		
		else												//works for last and first node as well
		{
			prevt1->next=temp1->next;
			prevt2->next=temp1;
			temp1->next=NULL;
			temp2->next=prevt1->next;
			prevt1->next=temp2;
		}
	}
	
	else
	{
		if(temp1->next==temp2)									//adjacent nodes
		{
			prevt1->next=temp2;
			temp1->next=temp2->next;
			temp2->next=temp1;	
		}
		else
		{
			prevt1->next=temp1->next;
			temp1->next=temp2->next;
			prevt2->next=temp1;
			temp2->next=prevt1->next;
			prevt1->next=temp2;
		}
	}
	
	return start1;
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
