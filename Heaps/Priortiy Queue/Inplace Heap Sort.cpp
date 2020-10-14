#include<iostream>
using namespace std;

void HeapSort(int pq[], int n)		//InPlace Heap Sort
{
	//Creating a heap from the input array
	
	for(int i=1; i<n; i++)				//a[0] is already a heap
	{
		int childIndex= i;
		
		while(childIndex > 0)			//ie childIndex becomes root
		{
			int parentIndex= (childIndex - 1)/2;
			
			if( pq[childIndex] < pq[parentIndex] )
			{
				int temp= pq[childIndex];
				pq[childIndex]= pq[parentIndex];
				pq[parentIndex]= temp;
			}
			else					// ie reached the correct position of the child
			{
				break;
			}
			
			childIndex= parentIndex;		//to continue the loop
		}
	}
	
	//RemoveMin()
	
	int size= n;
	
	while( size>1 )
	{
		int temp= pq[0];				//swapping the first element(min priority with)
		pq[0]= pq[size-1];				//with the last element
		pq[size-1]= temp;
		
		size--;							//one elment from the end always gets sorted with each iteration
		
		int parentIndex= 0;
		int leftChildIndex= 2*parentIndex + 1;
		int rightChildIndx= 2*parentIndex + 2;
		
		
		while ( leftChildIndex < size )	//if leftchildindex is out limit then rightchildindex
												//must be too cos it is a CBT. therefore only one condition required
		{
			int minIndex= parentIndex;
			
			if(pq[minIndex] > pq[leftChildIndex])
			{
				minIndex= leftChildIndex;
			}
			if( rightChildIndx < size && pq[minIndex] > pq[rightChildIndx] )		//if leftchildindex is in limit
																					//but right is not
			{
				minIndex= rightChildIndx;
			}
			
			
			if(parentIndex ==  minIndex)	//we have reached the correct position as the children
											// are larger than the parent
			{
				break;
			}
			
			int temp= pq[minIndex];
			pq[minIndex]= pq[parentIndex];
			pq[parentIndex]= temp;
			
			parentIndex= minIndex;
			leftChildIndex= 2*parentIndex+ 1;
			rightChildIndx= 2*parentIndex+ 2;
		}	
	}
	
	for(int i=0; i<n; i++)
	{
		cout<<pq[i]<<"\t";
	}

}

int main()
{
	int n;
	
	cout<<"Enter no. of elements: ";
	cin>>n;
	
	int a[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	
	HeapSort(a, n);
	
}
