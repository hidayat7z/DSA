#include<stdio.h>
#define MAX 25

int q[MAX],stack[MAX],front=-1,rear=-1,top=-1,k,n;

void ENQUE();
int DELQUE();
void push();
int pop();
void mainpart();

int main()
{
	int i,temp;
	
	printf("Enter the no. of elements you want to input((LESS THAN 10)):");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter element no. %d: ",i+1);
		scanf("%d",&temp);
		ENQUE(temp);
	}
	
	printf("Enter the position upto which you want the elements to be reversed:");
	scanf("%d",&k);
	
	mainpart();	
}

void mainpart()
{
	int i,a,b,c;
	
	for(i=0;i<k;i++)
	{
		a=DELQUE();
		push(a);
	}
	
	for(i=0;i<k;i++)
	{
		b=pop();
		ENQUE(b); 
	}
	
	for(i=k;i>n;i++)
	{
		c=DELQUE();
		ENQUE(c);
	}
	
	for(i=n;i<=rear;i++)
		printf("%d  ",q[i])
}

void ENQUE(int val)
{
	if(rear==MAX-1)
		printf("OVERFLOW.");
	
	else
	{
		if(front==-1 && rear==-1)
		{
			front=0;
			rear=0;
		}
		else
			rear++;
			
		q[rear]=val;
	}
}

int DELQUE()
{
	int item;
	
	item=q[front];
	
	if(front==-1 && rear==-1)	
		printf("UNDERFLOW");
		
	else
	{
		if(front==rear)				
		{
			front=-1;
			rear=-1;
		}
		
		else
			front++;
	}
	
	return item;
}

void push(int val)
{
	int val;
	
	if(top==MAX-1)
		printf("OVERFLOW.\n");
	
	else
	{
		printf("\nEnter element to be inserted:");
		scanf("%d",&val);
		
		top++;
		
		stack[top]=val;
	}	
}

int pop()
{
	int item;
	
	if(top==-1)
		printf("UNDERFLOW.\n");
		
	else
	{
		item=stack[top];
		printf("Deleted element is %d.\n",item);
		
		top--;
	}
	
	return item;
}
