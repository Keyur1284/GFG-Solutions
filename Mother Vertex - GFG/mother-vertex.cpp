//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    
    void DFS (int node, vector<bool> &vis, vector<int> adj[])
    {
        vis[node] = true;
        
        for (auto &it : adj[node])
        {
            if (!vis[it])   
                DFS (it, vis, adj);
        }
    }
    
	int findMotherVertex(int V, vector<int>adj[])
	{
	    int mother = -1;
	    vector<bool> vis(V, false);
	    
	    for (int i = 0; i < V; i++)
	    {
	        if (!vis[i])
	        {
	            DFS (i, vis, adj);
	            mother = i;
	        }
	    }
	    
	    vis.assign(V, false);
	    DFS(mother, vis, adj);
	    
	    for (int i = 0; i < V; i++)
	    {
	        if (!vis[i])
	            return -1;
	    }
	            
	    return mother;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends