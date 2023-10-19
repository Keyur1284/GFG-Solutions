//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    int level = 0;
	    queue<int> q;
	    unordered_set<int> vis;
	    
	    q.emplace(0);
	    vis.emplace(0);
	    
	    while (!q.empty())
	    {
	        int size = q.size();
	        
	        while (size--)
	        {
	            int node = q.front();
	            
	            if (node == X)
	                return level;
	            
	            q.pop();
	            
	            for (auto &it : adj[node])
	            {
	                if (vis.count(it) == 0)
	                {
	                    q.emplace(it);
                        vis.emplace(it);
	                }
	                
	            }
	        }
	        
	        level++;
	    }
	    
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends