//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    
    Node *temp = NULL;
    
    void reverse (Node *curr, Node *prev)
    {
        while (curr)
        {
            temp = curr;
            Node* nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
    }
    
    struct Node* modifyTheList(struct Node *head)
    {
        Node *slow = head, *fast = head;
        
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast)
            slow = slow->next;
            
        if (slow == NULL)
            return head;
            
        reverse(slow, NULL);
        
        Node *front = head;
        Node *back = temp;
        
        while (back)
        {
            int data = front->data;
            front->data = back->data - front->data;
            back->data = data;
            front = front->next;
            back = back->next;
        }
        
        reverse(temp, NULL);
        
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends