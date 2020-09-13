#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start1= NULL;
struct node *start2= NULL;			
struct node *start3= NULL;

struct node *createList(struct node*,int);
void display(struct node*);
void split(int);

int main()
{
	int n,i,ch,val;
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
	
	split(n);
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

void split(int n)
{
	int n1,n2,i;
	struct node *temp;
	
	n1=n/2;
	n2=n-n/2;
	
	i=0;
	temp=start1;
	while(i<n1)
	{
		start2=createList(start2,temp->data);
		temp=temp->next;
		i++;
	}
	printf("\nElements of List 1 after splitting:\n");
	display(start2);
	printf("\n\n");
	
	i=0;
	while(i<n2)
	{
		start3=createList(start3,temp->data);
		temp=temp->next;
		i++;
	}
	printf("Elements of List 2 after splitting:\n");
	display(start3);
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
	
