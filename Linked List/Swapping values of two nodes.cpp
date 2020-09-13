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
	display(start1);
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

struct node *swap(int x1,int x2)
{
	int c1,c2,t;
	struct node *temp1,*temp2;
	
	x1=x1-1;
	x2=x2-1;
	
	c1=0;
	c2=0;
	
	temp1=start1;
	while(x1!=c1)
	{
		temp1=temp1->next;
		c1++;
	}
	
	temp2=start1;
	while(x2!=c2)
	{
		temp2=temp2->next;
		c2++;
	}
	
	t=temp1->data;
	temp1->data=temp2->data;
	temp2->data=t;
	
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
