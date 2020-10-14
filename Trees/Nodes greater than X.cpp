/* Count nodes

Given a tree and an integer x, find and return the number of Nodes which are greater than x.
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class TreeNode
{
	public:
		T data;
		vector <TreeNode <T>*> children;
		
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

int nodesGreaterThanX(TreeNode<int> *root, int x)
{
    int count=0;
    
    if(root->data > x)
    {
    	count=1;
	}
	else
	{
		count=0;
	}
	
	for(int i=0; i<root->children.size();i++)
	{
		count+= nodesGreaterThanX(root->children[i],x);
	}
	
	return count;
}


int main()
{
	int x;
	
	TreeNode<int>* root= takeInput();
	
	cout<<"Enter element: ";
	cin>> x;
	
	cout<<nodesGreaterThanX(root,x);
}
