#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue
{
	vector<int> pq;
	
	public:
		
	PriorityQueue()				//CONSTRUCTOR
	{
		
	}
	
	bool isEmpty()
	{
		return pq.size() == 0;
	}
	
	int getSize()
	{
		return pq.size();
	}
	
	int getMin()
	{
		if( isEmpty() )
		{
			return -1;			//EMPTY PQ
		}
		return pq[0];
	}
	
	void insert(int data)
	{
		pq.push_back(data);
		
		int childIndex= pq.size() - 1;
		
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
	
	int removeMin()
	{
		if( isEmpty() )
		{
			return 0;				//PQ is empty
		}
		
		int ans= pq[0];
		pq[0]= pq[pq.size()-1];		//min priority element is swapped with the last element
		
		pq.pop_back();				//min priorirty element is removed
		
		int parentIndex= 0;
		int leftChildIndex= 2*parentIndex + 1;
		int rightChildIndx= 2*parentIndex + 2;
		
		
		while ( leftChildIndex < pq.size() )	//if leftchildindex is out limit then rightchildindex
												//must be too cos it is a CBT. therefore only one condition required
		{
			int minIndex= parentIndex;
			
			if(pq[minIndex] > pq[leftChildIndex])
			{
				minIndex= leftChildIndex;
			}
			if( rightChildIndx < pq.size() && pq[minIndex] > pq[rightChildIndx] )		//if leftchildindex is in limit
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
		
		return ans;
	}
	
	void displayVECTOR()
	{
		cout<<"\nVECTOR: \n";
		for(int i=0;i<getSize();i++)
		{
			cout<<pq[i]<<"\t";
		}
	}

				
};

int main()
{
	PriorityQueue pq1;
	
	pq1.insert(100);
	pq1.insert(10);
	pq1.insert(15);
	pq1.insert(4);
	pq1.insert(17);
	pq1.insert(21);
	pq1.insert(67);
	
	pq1.displayVECTOR();
	
	
	cout<<endl<<pq1.getSize();
	cout<<endl<<pq1.getMin();
	
	cout<<endl<<endl;
	
	while( !pq1.isEmpty() )
	{
		cout<< pq1.removeMin()<<"\t";
	}
	
}
