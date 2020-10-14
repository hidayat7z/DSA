#include<iostream>
using namespace std;

int a[100],nI=0;

void insert(int data)
{
	a[nI]=data;
	nI++;
}

void deleteX()
{
	nI--;
	a[nI]= -999;
}

void printARRAY()
{
	cout<<"\n ARRAY: \n";
	for(int i=0; i<nI; i++)
	{
		cout<<a[i]<<"\t";
	}
}

void display()
{
	for(int i=0; i<nI; i++)
	{
		if(a[i]== -999)
			continue;
		
		cout<<a[i]<<": "<<a[2*i+1]<<" "<<a[2*i+2];
		cout<<endl;
	}
	
}

int main()
{
	int val,ch;
	char ans;
	
	do
	{
		printf("--------------");
		printf("\nMenu:\n Enter 1 to insert.\n Enter 2 to delete.\n Enter 3 to print level-wise\n Enter 4 to print array.\n");
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				printf("Enter the value:");
				cin>>val;
				insert(val);
				break;
				
			case 2:
				deleteX();
				break;
			
			case 3:
				display();
				break;
				
			case 4:
				printARRAY();
				
				
			default:
				cout<<"Invalid Input. Try Again.";
		}
		cout<<"Do you want to continue? Enter y/Y for yes.";
		cin>>ans;
		
	}while(ans=='y'||ans=='Y');
}
