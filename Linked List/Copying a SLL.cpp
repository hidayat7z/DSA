#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *start1=NULL;
struct node *start2=NULL;

struct node* createList1(struct node*,int);
struct node* createList2();
void display(struct node*);

int main()
{
	int i,n,val;

	printf("Enter the number of elements you want to enter:");
	scanf("%d",&n);

	printf("Enter the elements:");
	i=0;
	while(i<n)
	{
		scanf("%d",&val);
		start1=createList1(start1,val);
		i++;
	}

	printf("Elements of List 1 are: ");
	display(start1);

	start2=createList2();			//the returned value we must store it

	printf("Elements of List 2 are: ");
	display(start2);
}

struct node* createList1(struct node *start,int val)
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

struct node* createList2()
{
	struct node *nN,*temp1,*temp2;

	temp1=start1;
	temp2=start2;
	while(temp1!=NULL)
	{
		nN=(struct node*)malloc(sizeof(struct node));
		nN->data=temp1->data;
		nN->next=NULL;

		if(start2==NULL)
		{
			start2=nN;
			temp1=temp1->next;
		}

		else
		{
		    temp2=start2;           //VERY VERY IMPORTANT STEP..iski wajah se jhamela hua sab
		    while(temp2->next!=NULL)
            {
                temp2=temp2->next;
            }
			temp2->next=nN;
			temp1=temp1->next;
		}
	}

	return start2;
}

