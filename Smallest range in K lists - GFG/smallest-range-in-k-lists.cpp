//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
        
    struct Node {
        
        int data, row, col;
        
        Node (int _data, int _row, int _col)
        {
            data = _data;
            row = _row;
            col = _col;
        }
      
    };
    
    struct comp {
        
        bool operator()(Node &n, Node &m)
        {
            return n.data > m.data;
        }
    };
    
    
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        int maxi = 0, minRange = INT_MAX, start = -1, end = -1;
        priority_queue<Node, vector<Node>, comp> pq;    
        
        for (int i = 0; i < k; i++)
        {
            pq.emplace(Node(arr[i][0], i, 0));
            maxi = max(maxi, arr[i][0]);
        }
        
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            
            int mini = it.data, row = it.row, col = it.col;
            
            if (minRange > maxi - mini)
            {
                minRange = maxi - mini;
                start = mini;
                end = maxi;
            }
            
            if (col + 1 < n)
            {
                pq.emplace(Node(arr[row][col + 1], row, col + 1));
                maxi = max(maxi, arr[row][col + 1]);
            }
            
            else
                break;
        }
        
        return {start, end};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends