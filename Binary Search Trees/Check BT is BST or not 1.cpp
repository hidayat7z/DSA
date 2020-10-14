/* Searching in a BST.
	Input taken in the BST with same method as Binary Tree 
*/

#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BinaryTreeNode
{
	public:
		
		T data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;
		
		BinaryTreeNode(T data)
		{
			this->data= data;
			left= NULL;
			right= NULL;
		}
			
		~BinaryTreeNode()					//when one node, delete left= delete NULL
		{									// it's ok. there's no issue
			delete left;
			delete right;
		}
};

BinaryTreeNode<int>* takeInputLevelWise()
{
	int rootData;
	cout<<"Enter root data: ";
	cin>>rootData;
	
	if(rootData==-1)
		return NULL;
		
	BinaryTreeNode <int> *root= new BinaryTreeNode <int>(rootData);
	
	queue< BinaryTreeNode<int>* > pendingNodes;
	pendingNodes.push(root);
	
	while(pendingNodes.size() != 0)
	{
		BinaryTreeNode <int> *temp= pendingNodes.front();
		pendingNodes.pop();
		
		int leftdata;
		cout<<"Enter left child of "<<temp->data<<": ";
		cin>>leftdata;
			
		if(leftdata != -1)
		{
			BinaryTreeNode <int> *leftChild= new BinaryTreeNode <int>(leftdata);
			temp->left= leftChild;
			pendingNodes.push(leftChild);
		}
		
		int rightdata;
		cout<<"Enter right child of "<<temp->data<<": ";
		cin>>rightdata;
		if(rightdata != -1)
		{
			BinaryTreeNode <int> *rightChild= new BinaryTreeNode <int>(rightdata);
			temp->right= rightChild;
			pendingNodes.push(rightChild);
		}
	}
	return root;
}

int maximum(BinaryTreeNode<int> *root)
{
	if(root==NULL)
		return INT_MIN;
		
	return max( root->data, max( maximum(root->left), maximum(root->right) ) );		
}

int minimum(BinaryTreeNode<int> *root)
{
	if(root==NULL)
		return INT_MAX;
		
	return min( root->data, min( minimum(root->left), minimum(root->right) ) );		
}

bool isBST(BinaryTreeNode<int> *root)
{
	if(root==NULL)
		return true;
		
	int leftMax= maximum(root->left);
	int rightMin= minimum(root->right);
	
	bool output= (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
	
	return output;
}

void printLevelWise(BinaryTreeNode<int> *root) 
{
	if(root==NULL)
		return;
	
	queue< BinaryTreeNode<int>* > q;
	q.push(root);
	
	while( q.size() !=0)
	{
		BinaryTreeNode<int>* temp= q.front();
		q.pop();
		
		if(temp==NULL)
		{
			cout<<endl;
			
			if(q.size()!=0)
				q.push(NULL);
		}
		else
		{
			cout<<temp->data<<": ";
			
			if(temp->left!=NULL)
			{
				cout<<"L";
				q.push(temp->left);
				cout<<temp->left->data<<",";
			}
			else
				cout<<"";
			
			if(temp->right!=NULL)
			{
				cout<<"R";
				q.push(temp->right);
				cout<<temp->right->data<<endl;
			}
			else
				cout<<""<<endl;
		}
	}			
}

int main()
{
	BinaryTreeNode <int> *root= takeInputLevelWise();
	
	printLevelWise(root);
	
	cout<<"\nANS= "<<isBST(root);
	
	delete root;
}
