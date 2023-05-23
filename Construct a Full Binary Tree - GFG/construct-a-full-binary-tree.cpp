//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
  
    Node* makeTree (int &index, int &pos, int pre[], int preMirror[])
    {
        Node* vertex = new Node(pre[index++]);
            
        if (vertex->data != preMirror[pos])
        {
            vertex->left = makeTree(index, pos, pre, preMirror);
            vertex->right = makeTree(index, pos, pre, preMirror);
        }
        
        pos--;
        
        return vertex;
    }
  
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        int index = 0, pos = size - 1;
        
        Node *head = makeTree(index, pos, pre, preMirror);
        
        return head;
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends