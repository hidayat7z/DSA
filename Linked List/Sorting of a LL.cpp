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
struct node *swap(struct node*, struct node*);
struct node *sort(int);

int main()
{
	int n,i,val;
	
	printf("Enter the no. of elements of you want in the list: ");
	scanf("%d",&n);
	
	printf("Enter the elements of the list--\n");
	i=0;
	while(i<n)
	{
		scanf("%d",&val);
		start1=createList(start1,val);
		i++;
	}
	display(start1);
	printf("\n\n");
	
	start1=sort(n);
	
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

struct node* sort(int n)
{
	struct node *t;
	int i=0,j=0,c=0;
	
	while(i<n)
	{
		c=0;									//Optimised Bubble Sort
		t=start1;
		while(t->next!=NULL)
		{
			if(t->data > (t->next)->data)
			{
				c++;
				start1=swap(t,t->next);
			}
			
			else
			{
				t=t->next;
			}
			j++;				//to count no. of times the loop runs
			display(start1);
		}
		if(c==0)
			break;
			
		i++;
	}
	printf("\n\n[[Loop ran %d times...]]\n\n",j);
	return start1;
}


struct node *swap(struct node *temp1,struct node *temp2)
{
	struct node *prevt1,*prevt2,*temp3;
	
	if(temp1==start1)
	{
		temp1=start1;
	}
	
	else
	{
		prevt1=start1;
		while(prevt1->next!=temp1)
		{
			prevt1=prevt1->next;
		}
		
		prevt2=start1;
		while(prevt2->next!=temp2)
		{
			prevt2=prevt2->next;
		}
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
