#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class TreeNode
{
	public:
		
		T data;
		vector <TreeNode <T> *> children;
		
		TreeNode(T data)
		{
			this->data= data;
		}
};

TreeNode<int>* takeInput()
{
	int DATA;
	cout<<"Enter root data: ";
	cin>> DATA;
	
	TreeNode<int>* root= new TreeNode<int>(DATA);
	
	queue< TreeNode<int>* > pendingNodes;			//queue containing pointers to nodes
	
	pendingNodes.push(root);
	
	while( pendingNodes.size() !=0)
	{
		TreeNode<int>* temp= pendingNodes.front();
		pendingNodes.pop();
		int n;
		
		cout<<"Enter number of children of "<<temp->data<<": ";
		cin>> n;
		
		for(int i=0; i<n; i++)
		{
			cout<<"Enter "<<i<<"th child of "<<temp->data<<": ";
			cin>>DATA;
			
			TreeNode<int>* child= new TreeNode<int>(DATA);
			temp->children.push_back(child);
			
			pendingNodes.push(child);	
		}	
	}
	
	return root;
}

void printLevelWise(TreeNode<int>* root)
{
	queue< TreeNode<int>* > pendingNodes;			//queue containing pointers to nodes
	
	pendingNodes.push(root);
	
	while( pendingNodes.size() !=0)
	{
		TreeNode<int>* temp= pendingNodes.front();
		pendingNodes.pop();
		
		cout<<temp->data<<" : ";
		
		for(int i=0; i<temp->children.size(); i++)
		{
			cout<<temp->children[i]->data<<",";
			
			/*	to avoid comma at end:
			
				if( i< (temp->children.size()-1) )
					cout<<temp->children[i]->data<<",";
				else
					cout<<temp->children[i]->data;
			
			*/
			
			pendingNodes.push(temp->children[i]);	
		}
		cout<<endl;	
	}
}

int height(TreeNode<int>* root) 
{
   int h=0;
	
	for(int i=0; i< root->children.size(); i++)
	{
		int childHeight= height(root->children[i]);
		
		if(childHeight > h)
		{
			h= childHeight;
		}
	}
	
	return h+1 ;
}

int main()
{
	
	TreeNode<int>* root= takeInput();
	
	printLevelWise(root);
	
	cout<<"\nHeight of tree= "<<height(root)<<endl;
}
