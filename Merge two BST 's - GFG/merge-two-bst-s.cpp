//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    
    void pushNodes (stack<Node*> &st, Node* node)
    {
        while(node)
        {
            st.emplace(node);
            node = node->left;
        }
    }
    
    vector<int> merge(Node *root1, Node *root2)
    {
       stack<Node*> tree1, tree2;
       
       pushNodes (tree1, root1);
       pushNodes (tree2, root2);
       
       vector<int> merged;
       
       while (!tree1.empty() && !tree2.empty())
       {
           int val1 = tree1.top()->data;
           int val2 = tree2.top()->data;
           
           if (val1 <= val2)
           {
               merged.emplace_back(val1);
               Node* node = tree1.top();
               tree1.pop();
               pushNodes(tree1, node->right);
           }
           
           else
           {
               merged.emplace_back(val2);
               Node* node = tree2.top();
               tree2.pop();
               pushNodes(tree2, node->right);
           }
       }
       
       while (!tree1.empty())
       {
           int val1 = tree1.top()->data;
           
           merged.emplace_back(val1);
           Node* node = tree1.top();
           tree1.pop();
           pushNodes(tree1, node->right);
       }
       
       while (!tree2.empty())
       {
           int val2 = tree2.top()->data;
           
           merged.emplace_back(val2);
           Node* node = tree2.top();
           tree2.pop();
           pushNodes(tree2, node->right);
       }
       
       return merged;
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends